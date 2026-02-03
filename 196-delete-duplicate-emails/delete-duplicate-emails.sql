# Write your MySQL query statement below
delete p from Person p
join person p2 on p.email = p2.email
where p.id > p2.id