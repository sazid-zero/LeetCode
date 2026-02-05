# Write your MySQL query statement below
select m.product_id, m.year as first_year, m.quantity, m.price
from Sales m
join (
    select s.product_id, min(s.year) as first_year
    from Sales s
    group by s.product_id
) t
on m.product_id = t.product_id
and m.year = t.first_year