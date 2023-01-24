SELECT AVG(energy) FROM songs WHERE artist_id = (SELECT id FROM artists WHERE name = 'Drake');

-- Write a SQL query that returns the average energy of songs that are by Drake.
-- Should not assume anything about ID of any particular songs or artists: Your queries should be accurate even if the id of any particular song or person were different.
