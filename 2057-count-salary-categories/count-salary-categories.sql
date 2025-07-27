# Write your MySQL query statement below
SELECT "High Salary" AS 'category',COUNT(account_id) AS 'accounts_count'
FROM accounts
WHERE income > 50000
UNION 
SELECT "Average Salary" AS 'category', COUNT(account_id) AS 'accounts_count'
FROM accounts
WHERE income >=20000 AND income<=50000
UNION
SELECT "Low Salary" AS 'category' ,COUNT(account_id) AS 'accounts_count'
FROM accounts
WHERE income <20000
ORDER BY 'accounts_id' ASC;