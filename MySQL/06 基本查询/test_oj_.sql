CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N=N-1;
  RETURN (
        select distinct salary from Employee  order by salary desc limit 1 offset N
  );
END
select name,population , area from World where area>=3000000 or population >= 25000000;
select  p1.Email from Person p1, Person p2 where p1.id != p2.id and p1.email = p2.email;

select title, count(title) as t from titles group by title having t >= 2;
select dept_manager.dept_no, dept_manager.emp_no,salaries.salary from dept_manager,salaries where dept_manager.emp_no = salaries.emp_no and dept_manager.to_date='9999-01-01' and salaries.to_date='9999-01-01' order by dept_manager.dept_no;


insert into actor values(1,'PENELOPE','GUINESS','2006-02-15 12:34:33'),(2,'NICK','WAHLBERG','	2006-02-15 12:34:33') ;
select distinct salary from salaries order by salary desc;
select * from employees order by hire_date desc limit 1 offset 0;
select * from employees order by hire_date desc limit 1 offset 0;
select * from employees where  hire_date  =  (select distinct hire_date from employees order by hire_date desc limit 1 offset 2);
select emp_no ,count(emp_no) as t from salaries group by emp_no having t > 15;
