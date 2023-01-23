### Task: ###
**Implement a program that computes the approximate grade level needed to comprehend some text.**

### Specification: ###
Practice question similar to [Readability](https://github.com/Chong-Tuc-Yee/HarvardX-CS50-Introduction-to-Computer-Science/tree/main/Pset2/readability) in Pset2 but built in Python language.

Practice Question Source: [More Info](https://cs50.harvard.edu/x/2022/psets/6/readability/)

### Usage: ###
To run program, user can execute following commands in codespace terminal:
1. `cd Pset6`
2. `cd sentimental-readability`
3. `python readability.py`

User can then input text and program will output the grade level recommendation.

### Program Example: ###
```
$ python readability.py
Text: One fish. Two fish. Red fish. Blue fish.
Before Grade 1
```
```
$ python readability.py
Text: Would you like them here or there? I would not like them here or there. I would not like them anywhere.
Grade 2
```
```
$ python readability.py
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```
```
$ python readability.py
Text: Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or conversation?"
Grade 8
```
```
$ python readability.py
Text: When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.
Grade 8
```
```
$ python readability.py
Text: It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.
Grade 10
```
```
$ python readability.py
A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.
Grade 16+
```
