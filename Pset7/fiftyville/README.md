### Task: ###
**Based on database given on crime scene reports and etc., write SQL queries to solve the mystery.**

### Specification: ###
In this quest to solve the mystery of Fiftyville, the user need to identify:
- Who the thief is,
- What city the thief escaped to, and
- Who the thief’s accomplice is who helped them escape out of town

The initial clue given is that the theft took place on **July 28, 2021** and that it took place on **Humphrey Street**. <br>
User can start with **`crime_scene_reports`** table included in `fiftyville.db`.

Program includes following files:
1. `fiftyville.db`
    - A SQLite database containing tables of data from towns records from around time of theft.
    - Other clues can be traced from this database file.

2. `log.sql`
    - This file keeps a log of all SQL queries where user describes the whole process of solving the mystery.
    - The queries are labelled each with a comment describing why we’re running the query and/or what information we’re hoping to get out of that particular query.

3. `answers.txt`
    - This file contains user's answer for the mystery. 
    - Includes the name of the thief, the city that the thief escaped to, and the name of the thief’s accomplice who helped them escape town.

Practice Question Source: [More Info](https://cs50.harvard.edu/x/2022/psets/7/fiftyville/)

### Usage: ###
To run program, user can execute following commands in codespace terminal:
1. `cd Pset7`
2. `cd fiftyville`
3. To check out contents of the database, run command as below:
    - `sqlite3 fiftyville.db`
    - `.tables` to list out all the tables in the database.
    - `.schema TABLE_NAME` (where `TABLE_NAME` is the name of a table in the database) to list out all the title contents in the particular table.
