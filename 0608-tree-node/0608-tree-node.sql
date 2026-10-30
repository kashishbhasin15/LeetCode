# Write your MySQL query statement below
select t.id ,
   case 
      when t.p_id is NULL then 'Root'
      when id in (
        select p_id from tree
      ) then 'Inner'
      else 'Leaf'
    end as type
from tree t;