# Write your MySQL query statement below
(SELECT name  as results
FROM MovieRating AS m 
JOIN Users AS u ON m.user_id = u.user_id
Group BY name 
order by count(name) desc,name
limit 1)

union all
(SELECT title as results
from MovieRating as m 
join Movies as m1 
ON m.movie_id=m1.movie_id
WHERE date_format(created_at , '%Y-%m') = '2020-02'
Group BY title
order by avg(rating) desc,title
limit 1);

