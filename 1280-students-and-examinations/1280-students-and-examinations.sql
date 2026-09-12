# Write your MySQL query statement below
select s.student_id,s.student_name,n.subject_name,count(e.student_id) as attended_exams 
from subjects n cross join students s left join examinations e on s.student_id=e.student_id and e.subject_name=n.subject_name
group by s.student_id, s.student_name, n.subject_name
order by s.student_id,n.subject_name;