# Write your MySQL query statement below
SELECT distinct product_id,10 as price 
FROM Products
GROUP BY  product_id 
HAVING min(change_date) >'2019-08-16'

UNION

SELECT distinct product_id,new_price  as price from Products
WHERE(product_id,change_date)
IN(
    SELECT product_id , max(change_date)
    from Products
    WHERE change_date<="2019-08-16" 
    GROUP BY product_id
);
