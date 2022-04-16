SELECT
    employee_id
FROM
    (
        SELECT
            employee_id
        FROM
            employees
        UNION ALL
        SELECT
            employee_id
        FROM
            salaries
    ) AS t
GROUP BY
    employee_id
HAVING
    COUNT(employee_id) = 1
ORDER BY
    employee_id