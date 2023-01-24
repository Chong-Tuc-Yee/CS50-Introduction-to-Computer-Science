SELECT name FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Post Malone');

-- Write a SQL query that lists the names of songs that are by Post Malone.
-- Should not assume anything about ID of any particular songs or artists: Queries should be accurate even if the id of any particular song or person were different.
