# Write your MySQL query statement below
# ineer join only borrowed copies with the orders table 
select lb.book_id,lb.title,lb.author,lb.genre,lb.publication_year, borrowed as current_borrowers   
from library_books as lb
INNER JOIN 
(select book_id,count(*)as borrowed 
from borrowing_records
where return_date is null
group by book_id
) as br
on lb.book_id=br.book_id and lb.total_copies=br.borrowed
order by borrowed desc, lb.title asc;