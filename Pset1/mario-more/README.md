### Task:
**Implement a program which prints out a pyramid block with a fixed gap equal to width of two hashes in the middle (Similar to an obstacle in Mario game). The pyramid's height is based on user input.**

### Usage:
Program should behave as per examples below.<br>
User can only input a ***positive number*** between ***1*** and ***8***, inclusive. Else program will reprompt user for acceptable input.
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
