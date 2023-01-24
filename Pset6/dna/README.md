### Task: ###
**Implement a program that identifies a person based on their DNA.**

### Specification: ###
DNA is composed of a sequence of molecules called nucleotides.<br>
Each nucleotide contains one of four different bases: **`A`**, **`C`**, **`G`**, **`T`**.<br>
Some portions of the sequence are similar but some are different.<br>
The sequences that have higher genetic diversity occurs in **`Short Tandem Repeats`**(STR) where the no. of times of repeats of this short sequence of DNA varies a lot among individuals.<br>
Comparing **`multiple STRs`** can further improve accuracy of **`DNA profiling`**.

Files provided in this program include:
1. **`DNA databases for each individual`(csv file)** <br>
    Eg.
    ```
    name,AGAT,AATG,TATC
    Alice,28,42,14
    Bob,17,22,19
    Charlie,36,18,25
    ```
    where individual names and no. of repeats of different STRs for each person are listed.

2. **`DNA sequences`(txt file)**
    where sequnces of DNAs are provided.
    
The program will output whom the DNA most likely belongs to.

Practice Question Source: [More Info](https://cs50.harvard.edu/x/2022/psets/6/dna/)

### Usage: ###
To run program, user can execute following commands in codespace terminal:
1. `cd Pset6`
2. `cd dna`
3. `python dna.py [data.csv] [sequence.txt]` <br>
    Eg.
    ```
    $ python dna.py databases/large.csv sequences/5.txt
    Lavender
    ```
    
### Program Example: ###
If user did not provide any CSV data file or sequence txt file, prompt user for correct input format:
```
$ python dna.py
Usage: python dna.py data.csv sequence.txt
```
```
$ python dna.py data.csv
Usage: python dna.py data.csv sequence.txt
```
Program with correct input format should execute properly as below examples:
```
$ python dna.py databases/small.csv sequences/1.txt
Bob
```
```
$ python dna.py databases/small.csv sequences/2.txt
No match
```
```
$ python dna.py databases/small.csv sequences/3.txt
No match
```
```
$ python dna.py databases/small.csv sequences/4.txt
Alice
```
```
$ python dna.py databases/large.csv sequences/6.txt
Luna
```
```
$ python dna.py databases/large.csv sequences/7.txt
Ron
```
```
$ python dna.py databases/large.csv sequences/8.txt
Ginny
```
```
$ python dna.py databases/large.csv sequences/11.txt
Hermione
```
```
$ python dna.py databases/large.csv sequences/13.txt
No match
```
```
$ python dna.py databases/large.csv sequences/17.txt
Harry
```
```
$ python dna.py databases/large.csv sequences/19.txt
Fred
```
```
$ python dna.py databases/large.csv sequences/20.txt
No match
```
