# Write your MySQL query statement below
select e.name 
from Employee e
left join Employee f on e.id != f.id and e.id = f.managerId
group by f.managerId having count(f.managerId) >= 5
