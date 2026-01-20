# Write your MySQL query statement below

WITH second2 AS (
    SELECT salary 
    FROM Employee 
    WHERE salary < (SELECT MAX(salary) FROM Employee)
)
SELECT MAX(salary) AS SecondHighestSalary 
FROM second2;
