# Write your MySQL query statement below
SELECT employee_id, department_id
FROM (
    SELECT *,
           COUNT(*) OVER (PARTITION BY employee_id) AS cnt
    FROM Employee
) e
WHERE (cnt = 1) OR (primary_flag = 'Y');
