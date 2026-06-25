# Write your MySQL query statement below
SELECT a.employee_id,a.name, COUNT(DISTINCT(b.employee_id)) as reports_count, ROUND(AVG(b.age)) as average_age
FROM Employees a JOIN Employees b 
ON a.employee_id=b.reports_to
GROUP BY a.employee_id;