# Write your MySQL query statement below
delete p from person p inner join person a on p.email=a.email where p.id>a.id;