# Write your MySQL query statement below
select distinct num as ConsecutiveNums 
from Logs l1
where exists (
    select 1 from Logs l2
    where l2.num = l1.num and l2.id = l1.id + 1
) and exists (
    select 1 from Logs l3
    where l3.num = l1.num and l3.id = l1.id+2
)