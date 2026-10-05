# Write your MySQL query statement below
Select e1.name from Employee as e1 
JOIN (
    select managerID from Employee group by managerID having count(managerID) >= 5
) AS e2 
ON e1.id = e2.managerID;