# Write your MySQL query statement below
SELECT customer_id, COUNT(*) as count_no_trans FROM Visits a LEFT JOIN Transactions b ON a.visit_id=b.visit_id
WHERE transaction_id is null
GROUP BY customer_id
ORDER BY count_no_trans DEsc ;