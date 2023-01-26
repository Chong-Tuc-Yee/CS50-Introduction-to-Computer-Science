### Task: ###
**Implement a webpage that let users answers trivia questions.**

### Specification: ###
Design a webpage using `HTML`, `CSS` and `JavaScript` to let users answer trivia questions.

There are **two parts** to this trivia webpage:

**Part 1: Multiple Choice Question** <br>
- Implement a multiple choice question by including a `<h3>` heading for question text and a `button` for each of the answer choices.
- There should be at least three answer choices with exactly one correct answer.
- Implement logic so that buttons change colors when user clicks on them.
  - **Incorrect Answer**: Button turns **red** & text appear beneath question stating **"Incorrect."**
  - **Correct Answer**: Button turns **green** & text appear beneath question stating **"Correct!"**

**Part 2: Free Response Question** <br>
- Implement a free response question by including a `<h3>` heading for question text, an `input` field for user to type in response and a `button` to let user confirm their answer.
- Implement logic so that the text field changes color when a user confirms their answer.
  - **Incorrect Answer**: If the user types an incorrect answer and presses the confirmation button, the text field should turn **red** and text should appear beneath the question that says **“Incorrect”**.
  - **Correct Answer**: If the user types the correct answer and presses the confirmation button, the input field should turn **green** and text should appear beneath the question that says **“Correct!”**.
  
Practice Question Source: [More Info](https://cs50.harvard.edu/x/2022/labs/8/)
 
### Usage: ###
To run program, user can execute following commands in codespace terminal:
1. `cd Pset8`
2. `cd trivia`
3. `http-server` to start a web server that serves your webpage.

### Program Example: ###
![image](https://user-images.githubusercontent.com/107826905/214802155-9b415309-6358-4f72-8653-5cf2c63bd5c2.png)

#### Program Display on Incorrect Answer: ####

![image](https://user-images.githubusercontent.com/107826905/214802548-2db41a7f-5dec-46b8-9a42-ccb0998d3aa0.png)

#### Program Display on Correct Answer: ####

![image](https://user-images.githubusercontent.com/107826905/214802892-2d6002ed-fa32-48a9-a6c0-af335a876853.png)

