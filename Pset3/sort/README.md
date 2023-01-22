### Task: ###
**Analyze three sorting programs to determine which algorithms they use.**

### Specification: ###
Three executable sorting programs `sort1`, `sort2`, `sort3` were given which belong to either one of the below sort type:
- `Selection sort`
- `Bubble sort`
- `Merge sort`

Multiple `.txt` files were given which contains `n` lines of values in either order:
- `Reversed`
- `Shuffled`
- `Sorted`

Answers are recorded in `answers.txt` along with an explanation for each program.

### Usage: ###
To run the program, user can execute the following lines of commands in codespace terminal：
1. `cd Pset3`
2. `cd sort`
3. `make sort`
4. To run sort program on text files: `./[program_name] [text_file.txt]`  (Eg.`./sort1 reversed10000.txt`)
5. To check runtime of sort program on text files: `time ./[sort_file] [text_file.txt]` (Eg.`time ./sort1 reversed10000.txt`)
