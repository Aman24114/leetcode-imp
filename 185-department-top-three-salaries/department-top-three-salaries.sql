# Write your MySQL query statement below
SELECT d.name as  department, e1.name as employee , e1.salary as Salary
FROM Employee e1 JOIN department d on e1.departmentId = d.id
WHERE 3 >(SELECT COUNT(distinct(e2.salary))
FROM Employee e2
WHERE e2.salary > e1.salary
AND e1.departmentId = e2.departmentId);
