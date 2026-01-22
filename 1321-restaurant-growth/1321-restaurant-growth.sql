# Write your MySQL query statement below

WITH daily_sales AS (
    -- Step 1: Sum all amounts for each day
    SELECT visited_on, SUM(amount) AS daily_amount 
    FROM Customer 
    GROUP BY visited_on
),
rolling_stats AS (
    -- Step 2: Calculate 7-day rolling sum and average
    SELECT 
        visited_on, 
        SUM(daily_amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
        ROUND(AVG(daily_amount) OVER (ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW), 2) AS average_amount
    FROM daily_sales
)
-- Step 3: Filter to show only results where a full 7-day window exists
SELECT * 
FROM rolling_stats 
WHERE visited_on >= (SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY) FROM daily_sales)
ORDER BY visited_on;

