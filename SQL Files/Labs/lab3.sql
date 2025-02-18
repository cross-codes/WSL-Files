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
