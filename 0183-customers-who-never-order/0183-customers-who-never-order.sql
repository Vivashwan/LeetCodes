# Write your MySQL query statement below
SELECT name as Customers
FROM Customers
WHERE ID NOT IN(
    SELECT customerId
    FROM orders
)