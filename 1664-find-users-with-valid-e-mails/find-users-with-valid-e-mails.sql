# Write your MySQL query statement below
SELECT * 
FROM Users
WHERE REGEXP_LIKE(mail, '^[a-zA-Z][a-zA-Z0-9._-]*@leetcode\\.com$', 'c');
-- // start of the string 
-- // then folwoed by *
-- // then literal string 
-- // \\. esapce in my sql 
-- // com 
-- // end of liternal by dollar 
-- // regexp_like (string, pattern,flags)
-- c =case-sensitive i = case-insensitive

