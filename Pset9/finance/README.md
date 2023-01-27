### Task: ###
**Implement a website via which users can buy and sell stocks.**

### Specification: ###
Implement a web app, **C$50Finance** via which users can manage and portfolios of stock.

Framework: **Flask**

Function:
- Register user for a new account and enable existing users log in to their own accounts.
- Check stocks' actual prices and display current user's own portfolios' values via downloading stock quotes from API (Using [IEX](https://iexcloud.io/cloud-login#/)).
- Buy and sell stocks.
- Display current user's transaction history.  

*(Note: Free IEX account for querying stocks values only last for a month, hence user may need to recreate a new account for new API key for this project.)* <br>
*(Please follow configuration steps below for setting up the API key for this project.)*

Practice Question Source: [More Info](https://cs50.harvard.edu/x/2022/psets/9/finance/)

### Usage: ###
**Configuring**

Before starting this project, we’ll need to register for an API key in order to be able to query IEX’s data. To do so, follow these steps:

1. Visit https://iexcloud.io/cloud-login#/register/.
2. Select the “Individual” account type, then enter your name, email address, and a password, and click “Create account”.
3. Once registered, scroll down to “Get started for free” and click “Select Start plan” to choose the free plan.
4. Once you’ve confirmed your account via a confirmation email, visit https://iexcloud.io/console/tokens.
5. Copy the key that appears under the Token column (it should begin with pk_).
6. In your terminal window, execute:
   - `cd Pset9`
   - `cd finance`
   - `$ export API_KEY=value`
   where value is that (pasted) value, without any space immediately before or after the =. You also may wish to paste that value in a text document somewhere, in case you need it again later.

**Running**

Next, to start Flask's built-in web server, user can execute following commands in codespace terminal window:
1. `$ flask run`

To check out database `finance.db`, user can use program `PhpLiteAdmin` or execute:
1. `sqlite3 finance.db`
2. `.schema`
