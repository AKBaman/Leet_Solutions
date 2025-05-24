# Write your MySQL query statement below
-- select name from customer where id not in (select id from Customer
-- where referee_id in (2));

select name from Customer
where referee_id != 2 or referee_id is null;
