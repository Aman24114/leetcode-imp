# Write your MySQL query statement below
select t.request_at as Day,
ROUND(sum(t.status!='completed')/count(*),2) as "Cancellation Rate"
FROM Trips t
JOIN Users c
on t.client_id=c.users_id AND c.banned='No'
JOIN Users d
on t.driver_id=d.users_id AND d.banned='No'
where request_at between '2013-10-01' AND '2013-10-03'
GROUP BY request_at;
