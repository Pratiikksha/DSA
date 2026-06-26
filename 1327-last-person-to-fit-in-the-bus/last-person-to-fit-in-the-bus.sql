# Write your MySQL query statement below
SELECT person_name FROM (
    SELECT b.person_name,b.turn as turn,SUM(a.weight) as running_sum
    FROM
Queue a JOIN Queue b 
ON a.turn<=b.turn
GROUP BY b.turn) t
where t.running_sum<=1000
ORDER BY t.turn DESC
LIMIT 1;
