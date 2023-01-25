SELECT DISTINCT name
FROM people JOIN stars ON people.id = stars.person_id
WHERE name != "Kevin Bacon"
AND movie_id IN (
    SELECT movie_id
    FROM stars JOIN people ON stars.person_id = people.id
    WHERE name = "Kevin Bacon"
    AND birth = 1958
);

-- Write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
-- There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
-- Kevin Bacon himself should not be included in the resulting list.
