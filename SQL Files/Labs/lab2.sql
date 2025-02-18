-- Question 1
INSERT INTO
  department (dept_name, building, budget)
VALUES
  ("Biology", "CVR", 890976.89);

-- Question 2
UPDATE student
SET
  tot_cred = 200
WHERE
  name = "Im";

-- Question 3
DELETE FROM student
WHERE
  ID = 1968;

-- Question 4
SELECT
  *
FROM
  student;

SELECT
  ID,
  name
FROM
  instructor;

-- Question 5
SELECT
  *
FROM
  course
WHERE
  dept_name = "Comp. Sci.";

SELECT
  *
FROM
  student
where
  tot_cred > 30;

-- Question 6
SELECT
  *
FROM
  instructor
ORDER BY
  salary DESC;

SELECT
  *
FROM
  section
ORDER BY
  year,
  semester;

-- Question 7
SELECT
  dept_name,
  COUNT(course_id) as num_courses
FROM
  course
GROUP BY
  dept_name;

SELECT
  dept_name,
  AVG(salary) as avg_salary
FROM
  instructor
GROUP BY
  dept_name;

-- Question 8
-- First question is incorrect, skipping
SELECT
  dept_name,
  AVG(salary) AS avg_salary
FROM
  instructor
GROUP BY
  dept_name
HAVING
  avg_salary > 50000;

-- Question 9
SELECT
  COUNT(DISTINCT semester) as num_semesters
from
  takes;

-- Question 10
SELECT
  ID,
  name,
  salary
from
  instructor
where
  salary BETWEEN 30000 AND 50000;

SELECT DISTINCT
  course_id,
  year
from
  takes
where
  year BETWEEN 2004 and 2010;

-- Question 11
SELECT
  course_id
FROM
  takes
where
  semester in ("Fall")
GROUP BY
  course_id;

SELECT
  ID,
  name,
  dept_name
from
  student
where
  dept_name NOT IN ("Math", "GEOLOGY", "English");

-- Question 12
SELECT
  course_id
FROM
  course
WHERE
  dept_name IS NULL;

-- Question 13
SELECT
  course_id,
  title
FROM
  course
WHERE
  title LIKE "%Data%";

-- Question 13
SELECT
  course_id,
  title,
  CASE
    WHEN credits = 1 THEN "Low Credit"
    WHEN credits = 2 THEN "Moderate Credit"
    WHEN credits > 2 THEN "High Credit"
    ELSE "Unknown"
  END AS score
from
  course;

-- Question 14 is trivial, skipping
-- EXTRA Questions -> These belong to the next lab sheet
-- Question 2
SELECT
  t.ID,
  SUM(c.credit * gp.point) / SUM(c.credit) AS GPA
FROM
  takes t
  JOIN course c ON t.course_id = c.course_id
  JOIN Grades gp ON t.grade = gp.grade
WHERE
  t.ID = 12345
GROUP BY
  t.ID;
