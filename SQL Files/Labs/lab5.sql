-- Question 1
SELECT DISTINCT
  (email)
FROM
  customer
WHERE
  store_id = 1;

-- Question 2
SELECT
  CONCAT (first_name, " ", last_name) AS CustomerName
FROM
  customer
WHERE
  customer_id IN (
    SELECT
      customer_id
    FROM
      payment
    WHERE
      staff_id = 1
  );

-- Question 3
SELECT
  CONCAT (first_name, " ", last_name)
FROM
  customer
WHERE
  customer_id NOT IN (
    SELECT
      customer_id
    FROM
      payment
    WHERE
      staff_id = 3
  );

-- Question 4
SELECT
  title,
  rental_rate
FROM
  film
WHERE
  rental_rate BETWEEN (
    SELECT
      AVG(rental_rate) - 1.5
    FROM
      film
  ) AND (
    SELECT
      AVG(rental_rate) + 1.5
    FROM
      film
  );

-- Question 5
SELECT
  CONCAT (first_name, " ", last_name)
from
  customer
WHERE
  customer_id NOT IN (
    SELECT
      customer_id
    FROM
      customer
    WHERE
      store_id = 2
  );

-- Question 6, 7: IDK
-- Question 8, can also use ANY
SELECT
  film_id,
  title,
  rental_rate
from
  film
WHERE
  rental_rate > (
    SELECT
      MIN(rental_rate)
    FROM
      film
      INNER JOIN film_category ON film.film_id = film_category.film_id
      INNER JOIN category ON film_category.category_id = category.category_id
    WHERE
      category.name = "Action"
  );

-- Question 9
SELECT
  actor.first_name,
  actor.last_name
FROM
  actor
  INNER JOIN film_actor ON actor.actor_id = film_actor.actor_id
  INNER JOIN film_category ON film_actor.film_id = film_category.film_id
  INNER JOIN category ON film_category.category_id = category.category_id
GROUP BY
  actor.first_name,
  actor.last_name
HAVING
  COUNT(DISTINCT category.category_id) = (
    SELECT
      COUNT(DISTINCT category_id)
    FROM
      category
  );

-- Question 10: Question makes no sense
-- Question 11:
SELECT
  actor.first_name,
  actor.last_name
FROM
  actor
WHERE
  (
    SELECT
      COUNT(DISTINCT film_id)
    FROM
      film_actor
    WHERE
      film_actor.actor_id = actor.actor_id
  ) > 5;

-- Question 12
SELECT
  customer.customer_id,
  customer.first_name,
  customer.last_name,
  (
    SELECT
      AVG(amount)
    FROM
      (
        SELECT
          SUM(payment.amount) AS amount
        FROM
          payment
        GROUP BY
          payment.customer_id
      ) AS sub_payment
  ) AS avg_sum_payment_per_customer,
  (
    SELECT
      AVG(payment.amount)
    FROM
      payment
    WHERE
      payment.customer_id = customer.customer_id
  ) AS avg_payment_per_customer,
  (
    SUM(payment.amount) - (
      SELECT
        AVG(payment.amount)
      FROM
        payment
      WHERE
        payment.customer_id = customer.customer_id
    )
  ) AS diff_from_average
FROM
  customer
  INNER JOIN payment ON customer.customer_id = payment.customer_id
GROUP BY
  customer.customer_id,
  customer.first_name,
  customer.last_name;

-- Question 13
SELECT
  film.film_id,
  film.title,
  film.description,
  film.rental_rate,
  subquery.avg_rate
FROM
  film
  INNER JOIN film_category ON film.film_id = film_category.film_id
  INNER JOIN category ON film_category.category_id = category.category_id,
  (
    SELECT
      category.name as category,
      AVG(film.rental_rate) as avg_rate
    FROM
      film
      INNER JOIN film_category ON film.film_id = film_category.film_id
      INNER JOIN category ON film_category.category_id = category.category_id
    GROUP BY
      category.name
  ) subquery
WHERE
  category.name = subquery.category;

-- Question 14
SELECT
  actor.actor_id,
  actor.first_name,
  actor.last_name,
  COUNT(DISTINCT film_actor.film_id) as num_acted
FROM
  actor
  INNER JOIN film_actor ON actor.actor_id = film_actor.actor_id
GROUP BY
  actor.actor_id,
  actor.first_name,
  actor.last_name
HAVING
  COUNT(DISTINCT film_actor.film_id) > (
    SELECT
      AVG(film_count)
    FROM
      (
        SELECT
          COUNT(DISTINCT film_id) AS film_count
        FROM
          film_actor
        GROUP BY
          actor_id
      ) AS subquery
  );
