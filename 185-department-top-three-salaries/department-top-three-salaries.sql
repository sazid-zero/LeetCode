# Write your MySQL query statement below
/*
select d.name as Department, e.name as Employee, e.salary as Salary 
from Employee e
join Department d on e.departmentId = d.id
where e.salary = (
    select max(salary) from Employee
    where departmentId = e.departmentId
) or e.salary= (
    select max(salary) from Employee
    where departmentId = e.departmentId and salary < (select max(salary) from Employee
    where departmentId = e.departmentId)
) or e.salary = (
    select max(salary) from Employee
    where departmentId = e.departmentId and salary < (select max(salary) from Employee
    where departmentId = e.departmentId and salary < (select max(salary) from Employee
    where departmentId = e.departmentId))
)*/

SELECT d.name AS Department,
       e.name AS Employee,
       e.salary AS Salary
FROM (
    SELECT e.*,
           DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS rnk
    FROM Employee e
) e
JOIN Department d ON d.id = e.departmentId
WHERE rnk <= 3;
