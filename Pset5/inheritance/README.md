### Task: ###
**Implement a program that simulates the inheritance of blood types for each member of the family.**

### Specification: ###
A person's blood type is determined by two alleles.<br>
Three are three possible types of alleles, namely **`A`**, **`B`** and **`O`** of which each person has two.<br>
Each of the parents passes on one of their two blood type alleles to their child.<br>
The possible blood type combinations are: **`OO`**, **`OA`**, **`OB`**, **`AO`**, **`AA`**, **`AB`**, **`BO`**, **`BA`** and **`BB`**.

The program creates a family of a specified generation size and assigns blood type alleles to each family member.<br> 
The oldest generation will have alleles ***assigned randomly*** to them.<br>
The following generations then inherit one of the two alleles passed on by their parent generation.

Practice Question Source: [More Info](https://cs50.harvard.edu/x/2022/labs/5/)

### Usage: ###
To run the program, user can execute the following commands in the codespace terminal:
1. `cd Pset5`
2. `cd inheritance`
3. `make inheritance`
4. `./inheritance`

### Program Example: ###
*(Note: Randomly generated and follow inheritance rule)*
```
$ ./inheritance
Child (Generation 0): blood type OO
    Parent (Generation 1): blood type AO
        Grandparent (Generation 2): blood type OA
        Grandparent (Generation 2): blood type BO
    Parent (Generation 1): blood type OB
        Grandparent (Generation 2): blood type AO
        Grandparent (Generation 2): blood type BO
 ```
