# Write your MySQL query statement below
SELECT e1.name AS EMPLOYEE
FROM EMPLOYEE e1
WHERE 
(
    SELECT 1
    FROM Employee e2
    WHERE e2.id=e1.managerId
    AND e1.salary >e2.salary 
)