# Write your MySQL query statement below
SELECT id,
case 

when p_id is NULL then "Root"
when id in (SELECT p_id from Tree) then "Inner"
else "Leaf"

end as type 
from Tree;