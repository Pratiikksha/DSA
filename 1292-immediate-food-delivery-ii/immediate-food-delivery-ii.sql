# Write your MySQL query statement below
SELECT ROUND(SUM(CASE WHEN d.order_date=d.customer_pref_delivery_date THEN 1 ELSE 0 END)*100/COUNT(*),2) as immediate_percentage 
FROM
Delivery d INNER JOIN (
    SELECT customer_id,MIN(Order_date) as minDate FROM Delivery 
    GROUP BY customer_id
)f ON d.customer_id=f.customer_id AND d.order_date=f.minDate;