# Write your MySQL query statement below
select DISTINCT author_id as id
from Views Where viewer_id = author_id
order by id;