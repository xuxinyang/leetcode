SELECT
    email
FROM
(
    SELECT 
        email, COUNT(email) AS num
    FROM
        person
    GROUP BY
        email
) AS statistic
WHERE
    num > 1
;