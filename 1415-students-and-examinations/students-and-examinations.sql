# Write your MySQL query statement below
select s.student_id, s.student_name, sb.subject_name , count(e.student_id) attended_exams
from Students s
cross join Subjects sb
left join Examinations e on e.student_id = s.student_id
and e.subject_name = sb.subject_name
group by s.student_id, s.student_name, sb.subject_name
order by s.student_id, s.student_name, sb.subject_name