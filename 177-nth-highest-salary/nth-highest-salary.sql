CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary 
      FROM (
          SELECT salary, 
                 DENSE_RANK() OVER (ORDER BY salary DESC) AS salary_rank
          FROM Employee
      ) AS ranked_salaries
      WHERE salary_rank = N
  );
END
