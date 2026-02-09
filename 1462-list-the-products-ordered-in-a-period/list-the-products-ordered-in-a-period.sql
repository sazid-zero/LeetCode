# Write your MySQL query statement below
select p.product_name, sum(unit) as unit from products as p
join orders as od
on od.product_id=p.product_id
where month(order_date)=2 and year(order_date)=2020
group by p.product_name
having sum(unit)>=100 
