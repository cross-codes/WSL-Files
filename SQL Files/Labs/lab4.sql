-- Question 1
CREATE VIEW actor_view as
SELECT
  actor_id,
  first_name,
  last_name
FROM
  actor
WHERE
  first_name LIKE "A%";

-- Question 2
-- Average rating does not make sense because each film is unique?
CREATE VIEW high_rated_movies AS
SELECT
  film.film_id,
  film.title,
  film.rating
FROM
  film
  INNER JOIN film_category ON film.film_id = film_category.film_id
  INNER JOIN category ON film_category.category_id = category.category_id
WHERE
  category.name = "Action";

-- Question 3
SELECT
  customer.customer_id,
  customer.first_name,
  customer.last_name,
  payment.payment_date,
  payment.amount,
  SUM(payment.amount) OVER (
    PARTITION BY
      customer.customer_id
    ORDER BY
      payment.payment_date
  ) AS running_total
FROM
  customer
  INNER JOIN payment ON customer.customer_id = payment.customer_id;

-- Question 4
SELECT
  rental.customer_id,
  customer.first_name,
  customer.last_name,
  rental.rental_id,
  rental.return_date - rental.rental_date AS rental_duration,
  AVG(rental.return_date - rental.rental_date) OVER (
    PARTITION BY
      rental.customer_id
  ) AS avg_rental_duration
FROM
  rental
  INNER JOIN customer ON rental.customer_id = customer.customer_id;

-- Question 4
SELECT
  rental.customer_id,
  customer.first_name,
  customer.last_name,
  rental.rental_id,
  rental.return_date - rental.rental_date AS rental_duration,
  AVG(rental.return_date - rental.rental_date) OVER (
    PARTITION BY
      rental.customer_id
  ) AS avg_rental_duration
FROM
  rental
  INNER JOIN customer ON rental.customer_id = customer.customer_id;

-- Question 5
SELECT
  customer.store_id,
  customer.first_name,
  customer.last_name,
  payment.amount,
  MAX(payment.amount) OVER (
    PARTITION BY
      customer.store_id
  ) AS max_payment_in_store
FROM
  customer
  INNER JOIN payment ON customer.customer_id = payment.customer_id;

-- Question 6
SELECT
  customer.customer_id,
  customer.first_name,
  customer.last_name,
  SUM(payment.amount) as total_amount_paid,
  NTILE (4) OVER (
    ORDER BY
      SUM(payment.amount) DESC
  ) AS payment_tier
FROM
  customer
  INNER JOIN payment ON customer.customer_id = payment.customer_id
GROUP BY
  customer.customer_id,
  customer.first_name,
  customer.last_name
ORDER BY
  total_amount_paid DESC;

-- Question 7
SELECT
  customer.customer_id,
  customer.first_name,
  customer.last_name,
  payment.payment_date,
  payment.amount,
  LAG (payment.amount, 1, 0) OVER (
    ORDER BY
      customer.customer_id,
      payment.payment_date
  ) AS previous_payment,
  LEAD (payment.amount, 1, 0) OVER (
    ORDER BY
      customer.customer_id,
      payment.payment_date
  ) AS next_payment
FROM
  customer
  INNER JOIN payment ON customer.customer_id = payment.customer_id;

-- Question 8
SELECT
  rental_id,
  customer_id,
  rental_date,
  return_date,
  DATEDIFF (return_date, rental_date) AS rental_duration,
  CASE
    WHEN DATEDIFF (return_date, rental_date) > 5 THEN (DATEDIFF (return_date, rental_date) - 5) * 2
    ELSE 0
  END AS late_fee_estimate
FROM
  rental;

-- Question 9
SELECT
  customer_id,
  first_name,
  last_name,
  CONCAT (first_name, " ", last_name) AS full_name
FROM
  customer;

-- Question 10
SELECT
  customer_id,
  first_name,
  last_name,
  SUBSTRING(last_name, 1, 3) AS short_last_name
FROM
  customer;

-- Question 11
SELECT
  customer_id,
  first_name,
  last_name,
  CONCAT (
    TRIM(
      BOTH ' '
      FROM
        first_name
    ),
    TRIM(
      BOTH ' '
      FROM
        last_name
    )
  ) AS trimmed_name
FROM
  customer;

-- Question 12
SELECT
  customer_id,
  first_name,
  last_name,
  CONCAT (UPPER(first_name), " ", UPPER(last_name)) AS upper_name
FROM
  customer;

SELECT
  customer_id,
  first_name,
  last_name,
  CONCAT (LOWER(first_name), " ", LOWER(last_name)) AS lower_name
FROM
  customer;

-- Question 13
SELECT
  actor_id,
  last_name,
  CHAR_LENGTH(last_name) AS last_name_length
FROM
  actor;

SELECT
  REPLACE (last_name, "A", "@") as last_name
FROM
  actor;

-- Question 14
SELECT
  rental_id,
  rental_date,
  return_date,
  CURRENT_DATE(),
  CURRENT_TIMESTAMP()
FROM
  rental;

-- Question 15
-- Function resolution: No whitespace between function name and (
SELECT
  rental_id,
  rental_date,
  return_date,
  ADDDATE(rental_date, 30) AS future_rental_date,
  SUBDATE(rental_date, 30) AS past_rental_date
FROM
  rental;

-- Question 16
SELECT
  rental_id,
  rental_date,
  return_date,
  EXTRACT(
    YEAR_MONTH
    FROM
      rental_date
  ),
  EXTRACT(
    DAY_MINUTE
    FROM
      return_date
  )
FROM
  rental;
