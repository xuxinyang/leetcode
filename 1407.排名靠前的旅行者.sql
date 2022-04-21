SELECT
    name, coalesce(sum(distance), 0) travelled_distance
FROM
    users u
LEFT JOIN rides r ON u.id = r.user_id
GROUP BY
    name
ORDER BY
    travelled_distance DESC, name;