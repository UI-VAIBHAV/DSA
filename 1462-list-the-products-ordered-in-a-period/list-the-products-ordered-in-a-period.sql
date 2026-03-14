# Write your MySQL query statement below
select p.product_name,sum(o.unit) as unit
from products as p
join orders as o
on p.product_id = o.product_id
where o.order_date BETWEEN '2020-02-01' AND '2020-02-29'
group by p.product_name
having sum(o.unit)>=100;