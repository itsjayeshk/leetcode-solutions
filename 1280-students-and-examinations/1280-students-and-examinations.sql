# Write your MySQL query statement below
SELECT c.student_id,c.student_name,s.subject_name,COUNT(e.student_id) AS attended_exams
FROM Students c CROSS JOIN Subjects s LEFT JOIN Examinations e
ON e.student_id = c.student_id AND s.subject_name = e.subject_name
GROUP BY c.student_id,c.student_name,s.subject_name
ORDER BY c.student_id,s.subject_name ;

