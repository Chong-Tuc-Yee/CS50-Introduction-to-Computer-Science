### Task: ###
**Write SQL queries to answer questions about a database of songs.**

### Specification: ###
*(Note: Program used to store data and manipulate database in this course project is SQLite)*

Provided files:
1. `songs.db`
  - A SQLite database that stores data from Spotify about songs and their artists.
  - This dataset contains the top 100 streamed songs on Spotify in 2018.

2. `[number].sql` where number: 1~8
- A requirement is specified in each `.sql` file. 
- The correct answer ie. `single SQL query` will be input by user and recorded in file that will perform the action same as the requirement.

Practice Question Source: [More Info](https://cs50.harvard.edu/x/2022/labs/7/)

### Usage: ###
To run the program and test out the SQL queries, user can execute the following commands in codespace terminal:
1. `cd Pset7`
2. `cd songs`
3. `$ cat filename.sql | sqlite3 songs.db` where filename.sql contains the SQL queries eg. `1.sql`

To check out the contents of all tables in the database, user can execute following commands instead of step 3 in above:
1. `sqlite3 songs.db`
2. `.schema`

### Program Example: ###
![image](https://user-images.githubusercontent.com/107826905/214354139-208b778d-3c1f-409f-96e0-7b26a1ad6e3e.png)


