### Task: ###
**Write SQL queries to answer questions about a database of movies.**

### Specification: ###
Files provided:
1. `movies.db` 
    - A SQLite database that stores data from IMDb about movies, the people who directed and starred in them and ratings.
    - File not included in here as size too large. User can get it from following link and run commands in codespace terminal: 
      - `wget https://cdn.cs50.net/2021/fall/psets/7/movies.zip`
      - `unzip movies.zip`
      - `rm movies.zip`
      -  Copy over the SQL queries from each **`[number].sql`** file where **`number: 1 ~ 13`**, so user can test it out.

2. `[number].sql files` where `number: 1 ~ 13`
    - A list of SQL files each representing a different question requirement.
    - User have to input our own SQL query based on question requirement.

Practice Question Source: [More Info](https://cs50.harvard.edu/x/2022/psets/7/movies/) (*Please check out link for questions requirements and etc.*)

### Usage: ###
To run program, user can execute following commands in codespace terminal after getting `movies.db` file and copy over the queries into each `.sql` file as mentioned above:
1. `cd Pset7`
2. `cd movies`
3. `cat [number].sql | sqlite3 movies.db` where `numbers: 1 ~ 13` <br>
    (Eg. `$ cat 1.sql | sqlite3 movies.db`)
    
    Alternatively, user can also run this command for the 3rd step: <br>
    `$ cat filename.sql | sqlite3 movies.db > output.txt` to redirect output of query to a text file called `output.txt`
    
To check out the contents of all tables in the database, user can execute following commands instead of step 3 in above:
1. `sqlite3 movies.db`
2. `.schema`

### Program Testing: ###

User can check whether output from query matches the question requirement for each. <br>
User can also check for the total number of outputs in columns and rows: <br>
1.  Executing 1.sql results in a table with 1 column and 9,952 rows.
2.  Executing 2.sql results in a table with 1 column and 1 row.
3.  Executing 3.sql results in a table with 1 column and 69,705 rows.
4.  Executing 4.sql results in a table with 1 column and 1 row.
5.  Executing 5.sql results in a table with 2 columns and 11 rows.
6.  Executing 6.sql results in a table with 1 column and 1 row.
7.  Executing 7.sql results in a table with 2 columns and 7,046 rows.
8.  Executing 8.sql results in a table with 1 column and 4 rows.
9.  Executing 9.sql results in a table with 1 column and 18,730 rows.
10. Executing 10.sql results in a table with 1 column and 2,236 rows.
11. Executing 11.sql results in a table with 1 column and 5 rows.
12. Executing 12.sql results in a table with 1 column and 6 rows.
13. Executing 13.sql results in a table with 1 column and 185 rows.

Note that row counts do not include header rows that only show column names.
