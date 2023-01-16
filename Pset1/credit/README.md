### Task:
**Implement a program that prompts user to input a credit card number and program will check whether it is valid credit card number 
and reports whether it is American Express, Mastercard or Visa card number according to Luhn's algorithm**
### Usage:
Program should behave as per examples below.<br>
Identify following types of merchant:
- American Express
- Mastercard
- Visa
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
