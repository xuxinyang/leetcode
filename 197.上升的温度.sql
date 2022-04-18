SELECT
    weather.id AS 'weather_id',
FROM
    weather
JOIN
    weather w ON DATEDIFF(weather.RecordDate, w.RecordDate) = 1
    AND
    weather.Temperature > w.Temperature
;