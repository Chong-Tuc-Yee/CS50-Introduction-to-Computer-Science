### Task: ###
**Implement a program that spell-checks a file, using a hash table.**

### Specification: ###
Practice Question Source: [More Info](https://cs50.harvard.edu/x/2022/psets/5/speller/)

### Usage: ###
To run program, user can execute following commands in codespace terminal:
1. `cd Pset5`
2. `cd speller`
3. `make speller`
4. To run program on outting mispelled words, by default usage: `speller [dictionary] text` <br>
(Note: Provision of `[dictionary]` is optional and if omitted program will run `dictionaries/large` by default.) <br>
Hence, running `./speller text` is equivalent to running `./speller dictionaries/large text`. <br>
To execute program, user can just run `./speller texts/[txt file]` (Eg.`./speller texts/lalaland.txt`).

### Program Example: ###
(Note: Statistics are omitted in below example)
```
MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]
Sebastian's
[...]

WORDS MISSPELLED:
WORDS IN DICTIONARY:
WORDS IN TEXT:
TIME IN load:
TIME IN check:
TIME IN size:
TIME IN unload:
TIME IN TOTAL:
```
