### Task: 
**Implement a program that executes a substitution cipher as per below:**
```
$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
plaintext:  HELLO
ciphertext: VKXXN
```
Encryption of message: Use ***key*** (user input key) to map and replace each of the letters in ***plaintext*** (message input by user) with the letter it corresponds to in ***key***.
This will generate ***ciphertext*** (encrypted message). 

### Usage:
Program should behave as per examples below.

***Plaintext:***

- *Punctuations eg. commas and spaces are not replaced.*<br>
- *Case of letters are preserved ie. Uppercase letters in message remain uppercase, lowercase letters in message remain lowercase.*
- *Input by user must be alphabetical letters.*

***Key:***

- *Uppercase or lowercase letters doesn't matter during encryption, ie. a key of `VCHPRZGJNTLSKFBDQWAXEUYMOI` is identical to `vchprzgjntlskfbdqwaxeuymoi` and `VcHpRzGjNtLsKfBdQwAxEuYmOi`*
- *Input by user must be alphabetical letters and contains 26 letters.*

***Error Message:***

*If user does not provide valid key:*
```
$ ./substitution ABC
Key must contain 26 characters.
```
*If user provides no key:*
```
$ ./substitution
Usage: ./substitution key
```
*If user provides key with non-alphabets:*
```
$ ./substitution 1 2 3
Usage: ./substitution key
```

***Program Examples:***
```
$ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
plaintext:  HELLO
ciphertext: EHBBQ
```
```
$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  hello, world
ciphertext: jrssb, ybwsp
```
