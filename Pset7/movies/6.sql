SELECT AVG(rating)
FROM ratings JOIN movies ON ratings.movie_id = movies.id
WHERE year = 2012;

-- Write a SQL query to determine the average rating of all movies released in 2012.
