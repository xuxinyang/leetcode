SELECT
    user_id, CONCAT(UCASE(LEFT(name, 1)), LCASE(SUBSTRING(name, 2))) name
FROM
    users
ORDER BY
    user_id
;