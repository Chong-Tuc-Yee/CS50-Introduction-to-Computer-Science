### Task: ###
**Implement a program that applies filters to BMP image files.**

### Specification: ###
**Image Filtering:**
Taking pixels of original image and modifying each pixel in such a way that a particular effect is apparent in resulting image.

This practice comprises of implementation of 4 filters types:
- `Grayscale`
- `Reflection`
- `Blur`
- `Edges`

Practice Question Source: [More Info](https://cs50.harvard.edu/x/2022/psets/4/filter/more/)

### Usage: ###

To run program, user can run following commands in codespace terminal:

1. `cd Pset4`
2. `cd filter-more`
3. `make filter`
4. `./filter [filter] [original BMP image file] [output BMP image file]` (Eg. `./filter -r IMAGE.bmp REFLECTED.bmp`)<br>
(*Note:* `-b`: Blur filter ; `-e` : Edges filter ; `-g` : Grayscale filter ; `-r`  : Reflection filter)

Since scaling factor is 2.0, when listen to `output.wav`, it should be twice as loud as `input.wav`.
```
$ ./volume input.wav output.wav 2.0
```
Since scaling factor is 0.5, when listen to `output.wav`, it should be half as loud as `input.wav`.
```
$ ./volume input.wav output.wav 0.5
```
