### Task: ###
**Implement a program to modify the volume of an audio file.**

Eg. `$ ./volume input.wav output.wav 2.0`

### Specification: ###
Practice Question Source: [More info](https://cs50.harvard.edu/x/2021/labs/4/)

### Usage: ###

To run program, user can run following commands in codespace terminal:

1. `cd Pset4`
2. `cd volume`
3. `make volume`
4. `./volume [input wav file] [output wav file] [scaling factor]` (Eg. `./volume input.wav output.wav 2.0`)

Since scaling factor is 2.0, when listen to `output.wav`, it should be twice as loud as `input.wav`.
```
$ ./volume input.wav output.wav 2.0
```
Since scaling factor is 0.5, when listen to `output.wav`, it should be half as loud as `input.wav`.
```
$ ./volume input.wav output.wav 0.5
```
