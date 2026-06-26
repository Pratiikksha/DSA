# Write your MySQL query statement below
SELECT a.product_id, IFNULL(p.new_price,10) as price
FROM (select distinct(product_id) FROM Products) a
LEFT JOIN (select product_id,MAX(change_date) as dates FROM
Products WHERE change_date<='2019-08-16'
GROUP BY product_id) b
ON a.product_id=b.product_id
LEFT JOIN Products p
ON b.product_id=p.product_id and b.dates=p.change_date;