### Task:
**Analyze three sorting programs to determine which algorithms they use.**

### Usage:
Provided three already-compiled C programs, **`sort 1`**, **`sort 2`** and **`sort 3`**.<br>
Each of the programs implements a different sorting algorithm from below list:
- **`Selection sort`**
- **`Bubble Sort`**
- **`Merge Sort`**

**`sort1`**, **`sort2`**, and **`sort3`** are binary files, so you won’t be able to view the C source code for each. To assess which sort implements which algorithm, run the sorts on different lists of values.<br>
Multiple **`.txt`** files are provided where each file contains `n` lines of values, either reversed, shuffled or sorted.<br>

To run the sorts on the text files, in the terminal, run `./[program_name] [text_file.txt]` eg.`./sort1 reversed10000.txt`<br>
to time your sorts. To do so, run time `time ./[sort_file] [text_file.txt]` eg.`time ./sort1 reversed10000.txt`<br>
Answers are recorded in `answers.txt`.

