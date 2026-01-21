# Write your MySQL query statement below

WITH weight AS (
    SELECT 
        person_name, 
        SUM(weight) OVER (ORDER BY turn) AS ws
    FROM Queue
)
SELECT person_name
FROM weight
WHERE ws <= 1000
ORDER BY ws DESC
LIMIT 1;
