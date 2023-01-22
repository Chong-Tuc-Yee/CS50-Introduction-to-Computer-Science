### Task: ###
**Implement a program that recovers JPEGs from a forensic image.**<br>
Eg. `$ ./recover card.raw`

### Specification: ###
Deleted pics were originally JPEG images that were saved inside a memory storage.<br>
Using "signatures" of JPEG specific file format, user is required to recover each of the JPEG from `card.raw`, storing each as a separate file in your current working directory.<br>
The program should number each of the files it outputs as `###.jpg` where `###` is three-digit decimal from 000 on up. 

Practice Question Source: [More Info](https://cs50.harvard.edu/x/2022/psets/4/recover/) 

### Usage: ###

To run program, user can run following commands in codespace terminal:

1. `cd Pset4`
2. `cd recover`
3. `make recover`
4. `./recover card.raw`

Your program should behave per the examples below:
```
$ ./recover
Usage: ./recover IMAGE
```
where IMAGE is the name of the forensic image. For example:
```
$ ./recover card.raw
```

To check whether the JPEGs the program spit out are correct, simply double-click and take a look. If each photo appears intact, the operation was likely a success. <br>
A total of **49 JPG files** should be recovered.

![image](https://user-images.githubusercontent.com/107826905/213927953-dfce2035-0d3f-489b-b790-960e95b3fe2d.png)

