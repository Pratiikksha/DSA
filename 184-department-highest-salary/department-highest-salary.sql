# Write your MySQL query statement below
WITH highest as (
    select name, salary, departmentId,
    DENSE_RANK() OVER (Partition by departmentId order by salary desc) as rn
    from Employee
)
select d.name as Department, e.name as Employee, e.salary as Salary from
highest e JOIN Department d ON
e.departmentId = d.id 
where e.rn=1;