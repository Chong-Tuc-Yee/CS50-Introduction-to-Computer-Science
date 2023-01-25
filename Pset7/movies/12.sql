SELECT title
FROM movies JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name = "Johnny Depp"
AND movie_id IN (
    SELECT movie_id
    FROM stars JOIN people ON stars.person_id = people.id
    WHERE name = "Helena Bonham Carter"
);

-- Write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
-- You may assume that there is only one person in the database with the name Johnny Depp.
-- You may assume that there is only one person in the database with the name Helena Bonham Carter.
