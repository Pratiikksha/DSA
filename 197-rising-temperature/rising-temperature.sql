# Write your MySQL query statement below
SELECT a.id as Id FROM Weather a JOIN Weather b ON b.recordDate=DATE_SUB(a.recordDate,INTERVAL 1 DAY)
WHERE a.temperature>b.temperature;