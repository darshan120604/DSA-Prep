# Write your MySQL query statement below
SELECT
    r.contest_id,
    ROUND(COUNT(r.contest_id) * 100 / t.total, 2) AS percentage
FROM
    Register r
CROSS JOIN
    (SELECT COUNT(*) AS total FROM Users) AS t
GROUP BY
    r.contest_id
ORDER BY
    percentage DESC, r.contest_id ASC;

