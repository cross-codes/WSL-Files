-- Question 1
CREATE TABLE DEPARTMENT (
  Dname VARCHAR(15) NOT NULL UNIQUE,
  Dnumber INT NOT NULL PRIMARY KEY,
  Mgr_ssn CHAR(9) NOT NULL,
  Mgr_start_date DATE
);

CREATE TABLE EMPLOYEE (
  fname VARCHAR(15) NOT NULL,
  Minit CHAR,
  Lname VARCHAR(15) NOT NULL,
  Ssn CHAR(9) NOT NULL PRIMARY KEY,
  Bdate DATE NOT NULL,
  Address VARCHAR(30),
  Sex CHAR,
  Salary DECIMAL(10, 2),
  Super_ssn CHAR(9),
  Dno INT,
  FOREIGN KEY (Super_ssn) REFERENCES EMPLOYEE (Ssn),
  FOREIGN KEY (Dno) REFERENCES DEPARTMENT (Dnumber)
);

CREATE TABLE DEPT_LOCATIONS (
  Dnumber INT NOT NULL,
  Dlocation VARCHAR(15) NOT NULL,
  PRIMARY KEY (Dnumber, Dlocation),
  FOREIGN KEY (Dnumber) REFERENCES DEPARTMENT (Dnumber)
);

CREATE TABLE PROJECT (
  Pname VARCHAR(15) NOT NULL UNIQUE,
  Pnumber INT NOT NULL PRIMARY KEY,
  Plocation VARCHAR(15) NOT NULL,
  Dnum INT,
  FOREIGN KEY (Dnum) REFERENCES DEPARTMENT (Dnumber)
);

CREATE TABLE WORKS_ON (
  Essn CHAR(9) NOT NULL,
  Pno INT NOT NULL,
  Hours DECIMAL(3, 1),
  PRIMARY KEY (Essn, Pno),
  FOREIGN KEY (Essn) REFERENCES EMPLOYEE (Ssn),
  FOREIGN KEY (Pno) REFERENCES PROJECT (Pnumber)
);

CREATE TABLE DEPENDENT (
  Essn CHAR(9) NOT NULL,
  Dependent_name VARCHAR(15) NOT NULL,
  Sex CHAR,
  Bdate DATE,
  Relationship VARCHAR(8),
  PRIMARY KEY (Essn, Dependent_name),
  FOREIGN KEY (Essn) REFERENCES EMPLOYEE (Ssn)
);

-- Question 2
INSERT INTO
  DEPARTMENT
VALUES
  ("CSIS", 1000, "ABCDEFGHI", "2025-02-16"),
  ("Physics", 1001, "ABCDEFGHJ", "2025-02-17"),
  ("Biology", 1002, "ABCDEFGHK", "2025-02-18"),
  ("EEE", 1003, "ABCDEFGHL", "2025-02-19");

INSERT INTO
  EMPLOYEE
VALUES
  (
    "Akshaj",
    "I",
    "Rao",
    "1234ABCDE",
    "2004-03-22",
    "BD 1163",
    "M",
    "99999",
    "1234ABCDE",
    1001
  ),
  (
    "Sania",
    "B",
    "S",
    "1234ABXDE",
    "2004-12-25",
    "MR ????",
    "F",
    "99999",
    "1234ABXDE",
    1001
  ),
  (
    "Ishan",
    "E",
    "Raha",
    "1234ABCDL",
    "2004-02-26",
    "BD 1162",
    "M",
    "99999",
    "1234ABCDL",
    1000
  ),
  (
    "Arnav",
    "V",
    "Panda",
    "1234BBCDE",
    "2004-10-26",
    "BD 1157",
    "M",
    "1",
    "1234BBCDE",
    1003
  );

-- Rest are trivial, skipping
