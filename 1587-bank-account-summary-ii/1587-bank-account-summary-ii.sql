# Write your MySQL query statement below
SELECT u.name, SUM(t.amount) as balance
FROM Users u
LEFT JOIN Transactions t ON u.account = t.account
GROUP BY t.account
HAVING balance > 10000