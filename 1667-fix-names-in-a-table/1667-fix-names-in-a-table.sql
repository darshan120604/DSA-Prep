# Write your MySQL query statement below

-- Original Query logic adapted for SQL Server syntax
SELECT user_id, 
       CONCAT(UPPER(LEFT(name, 1)), LOWER(SUBSTR(name, 2))) AS name
FROM Users 
ORDER BY user_id;



