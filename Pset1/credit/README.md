### Task:
**Implement a program that prompts user to input a credit card number and program will check whether it is valid credit card number 
and reports whether it is American Express, Mastercard or Visa card number according to Luhn's algorithm**
### Usage:
Program should behave as per examples below.<br>
Identify following types of merchant:
- American Express
- Mastercard
- Visa
To run program, user can run following commands in codespace terminal:
1. `cd Pset1`
2. `cd credit`
3. `make credit`
4. `./credit`
```
$ ./credit
Number: 4003600000000014
VISA
```
Note: *`get_long`* function rejects hyphens(or more). Reprompt user for only inputs with correct format.
```
$ ./credit
Number: 4003-6000-0000-0014
Number: foo
Number: 4003600000000014
VISA
```
```
$ ./credit
Number: 6176292929
INVALID
```
