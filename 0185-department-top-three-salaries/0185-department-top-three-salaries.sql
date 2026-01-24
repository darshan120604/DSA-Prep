# Write your MySQL query statement below

WITH deptsal AS(
    SELECT 
        d.name AS dname, 
        e.name AS ename,
        e.salary AS salary,
        DENSE_RANK() OVER (PARTITION BY d.id ORDER BY e.salary DESC) AS sr
    FROM Department d JOIN Employee e 
    ON d.id = e.departmentId 
)
SELECT 
    dname AS Department, 
    ename AS Employee,
    salary AS Salary
FROM deptsal
WHERE sr < 4;
