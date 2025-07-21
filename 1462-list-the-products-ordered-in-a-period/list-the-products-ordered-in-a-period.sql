SELECT p.product_name , SUM(o.unit) as unit FROM Products as p
LEFT JOIN Orders as o on p.product_id = o.product_id
WHERE YEAR(o.order_date)='2020' AND MONTH(o.order_date)='02'
GROUP BY p.product_name
HAVING SUM(o.unit)>=100
