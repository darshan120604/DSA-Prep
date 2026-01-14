# Write your MySQL query statement below

SELECT name FROM Employee E JOIN (Select managerId , count(managerId) as cnt from Employee GROUP BY managerId ) m ON E.id = m.managerId WHERE cnt>4;