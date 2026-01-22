# Write your MySQL query statement below

WITH cnt as(
    -- Find user with most ratings, lexicographically smallest on tie
    SELECT 
        u.name as results
    FROM MovieRating mr 
    JOIN Users u ON mr.user_id = u.user_id  
    GROUP BY u.user_id
    ORDER BY COUNT(mr.movie_id) DESC, u.name ASC 
    LIMIT 1
),
av as (
    -- Find movie with highest average rating in Feb 2020, lexicographically smaller on tie
    SELECT 
        m.title as results
    FROM MovieRating mr 
    JOIN Movies m ON mr.movie_id = m.movie_id
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY mr.movie_id
    ORDER BY AVG(rating) DESC, m.title ASC 
    LIMIT 1
)

SELECT results FROM cnt
UNION ALL
SELECT results FROM av;


-- WITH cnt as(
--     SELECT 
--         u.name as name, 
--         COUNT(movie_id) OVER(Partition BY user_id, ORDER BY COUNT(movie_id) DESC, u.name ASC) as m    
--     FROM MovieRating mr JOIN Users u ON mr.user_id = u.user_id  LIMIT 1
-- )
-- av as (
--     SELECT 
--         mr.movie_id,
--         m.title as title,
--         AVG(rating) OVER(partition by mr.movie_id, order by Avg(rating) DESC,m.title ASC) as rt
--     FROM MovieRating mr JOIN Movies m ON mr.movie_id = m.movie_id LIMIT 1
-- )

-- SELECT name as result FROM cnt
-- UNION select title as result FROM av;