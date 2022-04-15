SELECT
    *
FROM
    patients
WHERE
    conditions RLIKE '^DIAB1|.*\\sDIAB1'
;