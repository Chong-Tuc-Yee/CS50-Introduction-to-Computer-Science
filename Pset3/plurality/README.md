### Task:
**Implement a program that runs a plurality election.**

### Specification:
In plurality vote, every voter gets to vote for one candidate. 
At the end of the election, whichever candidate has the greatest number of votes is declared the winner of the election.

User input required for *`candidates' names`*, *`number of voters`* and *`names of candidates voted for each voting person`*.
It is possible that the election could end in a tie if multiple candidates each have the maximum number of votes. In that case, you should output the names of each of the winning candidates, each on a separate line.

Practice Question Source: [More Info](https://cs50.harvard.edu/x/2021/psets/3/plurality/)

### Usage:
Program should behave as per examples below:
```
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice
Alice
```
```
$ ./plurality Alice Bob
Number of voters: 3
Vote: Alice
Vote: Charlie
Invalid vote.
Vote: Alice
Alice
```
```
$ ./plurality Alice Bob Charlie
Number of voters: 5
Vote: Alice
Vote: Charlie
Vote: Bob
Vote: Bob
Vote: Alice
Alice
Bob
```
