# Write your MySQL query statement below
SELECT 
    d.name as Department,
    e.name as Employee,
    e.salary as Salary
From Department d Join Employee e
ON d.id = e.departmentId
where(e.departmentId,e.salary) IN (
    SELECT departmentId,MAX(salary)
    From Employee Group by departmentId
)
;