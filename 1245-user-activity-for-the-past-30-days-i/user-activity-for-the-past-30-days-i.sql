# Write your MySQL query statement below
SELECT activity_date As day,COUNT(DISTINCT user_id)As active_users
FROM Activity 
WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'
GROUP BY activity_date