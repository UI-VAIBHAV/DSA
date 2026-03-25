# Write your MySQL query statement below
SELECT DATE_FORMAT(trans_date, '%Y-%m') AS month,country,count(*) as trans_count,SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) as approved_count,sum(amount) as trans_total_amount, sum(case when state='approved' then amount else 0 END) as approved_total_amount
from Transactions
group by DATE_FORMAT(trans_date, '%Y-%m'),country;