-- Question 1
SELECT
  film_id,
  title
FROM
  film
WHERE
  release_year = (
    SELECT
      MIN(release_year)
    FROM
      film
  );

SELECT
  film_id,
  title
FROM
  film
WHERE
  release_year = (
    SELECT
      MAX(release_year)
    FROM
      film
  );

-- Question 2
SELECT
  AVG(rental_rate) as avg_rental_rate
FROM
  film;

-- Question 3
SELECT
  customer_id,
  AVG(amount) AS avg_amt_paid
FROM
  payment
GROUP BY
  customer_id;

-- Question 4
-- Incorrect because rental_duration does not exist. However, assuming it did,
SELECT
  COUNT(rental_id),
  AVG(rental_duration)
FROM
  rental
WHERE
  rental_duration > 5;

-- Question 5
SELECT
  rating,
  COUNT(*),
  AVG(rental_rate) AS avg_rental_rate
FROM
  film
GROUP BY
  rating
ORDER BY
  rating ASC;

-- Question 6
-- Empty set for 3.5, setting to 2.5
SELECT
  rating,
  COUNT(*),
  AVG(rental_rate) AS avg_rental_rate
FROM
  film
GROUP BY
  rating
HAVING
  avg_rental_rate >= 2.5
ORDER BY
  rating ASC;

-- Question 7
SELECT
  l.first_name,
  l.last_name,
  r.first_name,
  r.last_name
FROM
  actor l
  INNER JOIN actor r ON l.last_name = r.last_name;

-- Question 8
SELECT
  customer.customer_id,
  customer.first_name,
  customer.last_name,
  film.title
FROM
  customer
  INNER JOIN rental ON customer.customer_id = rental.customer_id
  INNER JOIN inventory ON rental.inventory_id = inventory.inventory_id
  INNER JOIN film on inventory.film_id = film.film_id;

-- Question 9
SELECT
  country.country,
  COUNT(DISTINCT customer.customer_id) as number_of_customers
FROM
  country
  INNER JOIN city ON city.country_id = country.country_id
  INNER JOIN address ON city.city_id = address.city_id
  INNER JOIN customer ON address.address_id = customer.address_id
GROUP BY
  country
HAVING
  number_of_customers >= 1
ORDER BY
  country ASC;

-- Question 10
SELECT
  customer.first_name,
  customer.last_name,
  actor.first_name,
  actor.last_name
FROM
  customer
  LEFT JOIN actor ON customer.last_name = actor.last_name;

-- Question 11
SELECT
  film.title,
  customer.first_name,
  customer.last_name
FROM
  film
  LEFT JOIN inventory ON film.film_id = inventory.film_id
  LEFT JOIN rental ON inventory.inventory_id = rental.inventory_id
  LEFT JOIN customer on rental.customer_id = customer.customer_id;

-- Question 12
SELECT
  film.title,
  customer.first_name,
  customer.last_name
FROM
  film
  CROSS JOIN customer;

-- Question 13 (No common columns between film and inventory?)
SELECT
  *
FROM
  film
  NATURAL JOIN inventory;

-- Question 14
SELECT
  first_name,
  last_name
FROM
  customer
UNION
SELECT
  first_name,
  last_name
FROM
  staff;

-- Question 15
SELECT
  first_name,
  last_name
FROM
  actor
UNION ALL
SELECT
  first_name,
  last_name
FROM
  customer;
