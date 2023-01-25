SELECT name
FROM people JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE title = "Toy Story";

-- Write a SQL query to list the names of all people who starred in Toy Story.
-- You may assume that there is only one movie in the database with the title Toy Story.
