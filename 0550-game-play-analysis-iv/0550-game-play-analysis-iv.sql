WITH FirstLogins AS (
    SELECT
        player_id,
        MIN(event_date) AS first_login_date
    FROM
        Activity
    GROUP BY
        player_id
),
ConsecutiveLogins AS (
    SELECT
        COUNT(DISTINCT F.player_id) AS consecutive_players
    FROM
        FirstLogins F
    JOIN
        Activity A
    ON
        F.player_id = A.player_id
        AND A.event_date = DATEADD(DAY, 1, F.first_login_date) -- Corrected date function for SQL Server
)
SELECT
    ROUND(CAST(C.consecutive_players AS DECIMAL) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM
    ConsecutiveLogins C;
