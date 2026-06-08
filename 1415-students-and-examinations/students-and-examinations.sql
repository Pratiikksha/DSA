# Write your MySQL query statement below
SELECT a.student_id,a.student_name,c.subject_name,COUNT(b.subject_name) as attended_exams
FROM Students a 
CROSS JOIN Subjects c
LEFT JOIN Examinations b
ON a.student_id=b.student_id  AND
b.subject_name=c.subject_name
Group BY a.student_id,a.student_name,c.subject_name ORDER BY a.student_id, c.subject_name;