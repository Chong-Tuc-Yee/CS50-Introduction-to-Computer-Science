### Task:
**Implement a program which prints out a pyramid block with a fixed gap equal to width of two hashes in the middle (Similar to an obstacle in Mario game). The pyramid's height is based on user input.**

Practice Question Source Link: [More Info](https://cs50.harvard.edu/x/2022/psets/1/mario/more/)

### Usage:
Program should behave as per examples below.<br>
User can only input a ***positive number*** between ***1*** and ***8***, inclusive. Else program will reprompt user for acceptable input.<br>
To run program, user can run following commands in codespace terminal.
1. `cd Pset1`
2. `cd mario-more`
3. `make mario`
4. `./mario`

Program examples:
```
$ ./mario
Height: 1
#  #
```
```
$ ./mario
Height: 2
 #  #
##  ##
```
```
$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```
```
$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########
```
```
$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```
