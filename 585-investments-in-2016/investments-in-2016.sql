# Write your MySQL query statement below
SELECT ROUND(SUM(tiv_2016),2) AS tiv_2016 FROM Insurance i1
WHERE (lat,lon) NOT IN (SELECT lat,lon FROM Insurance  i2 WHERE i1.pid !=i2.pid) 
AND tiv_2015 in (SELECT tiv_2015 FROM Insurance i2 where i1.pid !=i2.pid)