SELECT COUNT(*) AS nummovies  --COUNT(*) used to count no. of rows in group if no column name specified. Otherwise count no. of rows in group with NON-NULL values in specified column.
FROM ratings
WHERE rating = 10.0;

-- Write a SQL query to determine the number of movies with an IMDb rating of 10.0.
