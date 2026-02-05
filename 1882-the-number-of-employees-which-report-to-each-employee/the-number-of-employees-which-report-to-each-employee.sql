# Write your MySQL query statement below
select s.employee_id, s.name, count(e.employee_id) as reports_count,
round(avg(e.age)) as average_age
from Employees s
left join Employees e
on s.employee_id = e.reports_to
group by s.employee_id
having count(e.employee_id) >=1
order by s.employee_id
