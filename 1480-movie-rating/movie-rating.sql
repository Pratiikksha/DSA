# Write your MySQL query statement below
(SELECT a.name as results FROM
Users a LEFT JOIN MovieRating b
ON a.user_id=b.user_id 
GROUP BY a.user_id
ORDER BY COUNT(*) DESC,a.name ASC
LIMIT 1)
UNION ALL
(SELECT m.title
FROM Movies m LEFT JOIN
MovieRating r 
ON m.movie_id=r.movie_id
WHERE created_at BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY r.movie_id
ORDER BY AVG(r.rating) DESC, m.title ASC
LIMIT 1);