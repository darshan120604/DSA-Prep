# Write your MySQL query statement below

/* Get count for Low Salary */
SELECT 'Low Salary' AS category, COUNT(account_id) AS accounts_count
FROM Accounts
WHERE income < 20000

UNION ALL

/* Get count for Average Salary */
SELECT 'Average Salary' AS category, COUNT(account_id) AS accounts_count
FROM Accounts
WHERE income >= 20000 AND income <= 50000

UNION ALL

/* Get count for High Salary */
SELECT 'High Salary' AS category, COUNT(account_id) AS accounts_count
FROM Accounts
WHERE income > 50000;

-- WITH categ as(

-- SELECT account_id, (CASE WHEN income<20000 THEN "Low Salary"
--                          WHEN income>50000 THEN "High Salary"
--                          ELSE "Average Salary"
--                     END) as cat 
-- FROM Accounts 
-- )

-- SELECT cat, COUNT(account_id) as accounts_count FROM categ GROUP BY cat;