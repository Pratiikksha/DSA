# Write your MySQL query statement below
SELECT DISTINCT(a.num) as ConsecutiveNums FROM
Logs a JOIN Logs b JOIN Logs c 
ON a.id+1=b.id AND b.id+1=c.id 
AND a.num=b.num AND b.num=c.num;