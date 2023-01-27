import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]

    # Obtain data from transactions and users tables
    transactions_db = db.execute("SELECT symbol, SUM(shares) AS shares, price FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)
    cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    cash = cash_db[0]["cash"]

    return render_template("index.html", database = transactions_db, cash = cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # User reached route via POST (via Submitting a form)
    if request.method == "POST":

        # Casting done to convert shares to int type although form is type number
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        # Ensure symbol field is not blank and symbol exists in database
        if not symbol:
            return apology("Must input symbol, 403")

        # Get corresponding stock data from API. Input symbol all convert to uppercase
        stock_data = lookup(symbol.upper())

        if stock_data == None:
            return apology("Symbol not exist")

        # Ensure input shares is a positive integer
        if shares < 0:
            return apology("Input shares figure must be positive")

        # Get current stock pricing value. Stock_data["price"] dict value already casted into float value
        transaction_value = shares * stock_data["price"]

        # Get user ID from session
        user_id = session["user_id"]

        # Get cash value of user using obtained ID
        user_cashdict = db.execute("SELECT cash FROM users WHERE id = ?", user_id)

        # Ensure correct return json data: return jsonify(user_cashdict)
        # To obtain only the cash value figure from the cash dictionary. There is only 1 element for each user
        user_cash = user_cashdict[0]["cash"]

        # Evaluate if cash value sufficient to buy stocks
        if user_cash < transaction_value:
            return apology("Insufficient cash value")

        rem_cash = user_cash - transaction_value

        # Update cash data in table with remaining cash after purchasing stock
        db.execute("UPDATE users SET cash = ? WHERE id = ?", rem_cash, user_id)

        # Obtain current datetime when user place order to buy stock
        date = datetime.datetime.now()

        # Insert obtained info into transactions table
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES(?, ?, ?, ?, ?)", user_id, stock_data["symbol"], shares, stock_data["price"], date)

        # Display a message
        flash("Successfully bought shares!")

        # Redirect user to homepage
        return redirect("/")

    # User reached route via GET (via Clicking a link or redirect)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Obtain user ID from session and use it to find data from transactions table
    user_id = session["user_id"]
    transactions_db = db.execute("SELECT * FROM transactions WHERE user_id = ?", user_id)
    return render_template("history.html", transactions = transactions_db)


@app.route("/add_cash", methods=["GET", "POST"])
@login_required
def add_cash():
    """Personal Touch: Allow user to add cash"""
    # User reached route via POST
    if request.method == "POST":
        # Obtain new cash amount from form. Casting int to convert string to integer
        new_cash = int(request.form.get("new_cash"))

        # Ensure field not blank and valid cash value
        if not new_cash or new_cash <= 0:
            return apology("Must add in money")

        # Obtain user ID from session
        user_id = session["user_id"]

        # Obtain current cash value
        user_cashdict = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        user_cash = user_cashdict[0]["cash"]

        # Update new cash value
        updt_cash = user_cash + new_cash

        # Update new cash values into user table
        db.execute("UPDATE users SET cash = ? WHERE user_id = ?", updt_cash, user_id)

        # Display success message
        flash("Successfully added cash!")

        # Redirect user to homepage
        return redirect("/")

    # User reached route via GET
    else:
        return render_template("add.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # User reached route via POST (via Submitting a form)
    if request.method == "POST":

        symbol = request.form.get("symbol")

        if not symbol:
            return apology("Must input symbol, 403")

        # Get corresponding stock data from API. Input symbol all convert to uppercase
        stock_data = lookup(symbol.upper())

        if stock_data == None:
            return apology("Symbol not exist")

        """ If success redirect user to page where display stock info and return 3 variables from lookup function.
            Access each dict value & send data from backend to frontend."""
        return render_template("quoted.html", name = stock_data["name"], price = stock_data["price"], symbol = stock_data["symbol"])

    # User reached route via GET (via Clicking a link or redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # User reached route via POST (via Submitting a form)
    if request.method == 'POST':

        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Ensure username, password and confirmation password fields are not blank and matching passwords
        if not username:
            return apology("Must provide username", 403)

        if not password:
            return apology("Must provide password", 403)

        if not confirmation:
            return apology("Must provide confirmation password", 403)

        if password != confirmation:
            return apology("Passwords do not match")

        # Generate hashes for the entered password
        hash = generate_password_hash(password)

        # Check if username already exists in database
        try:
            new_user = db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)
        except:
            return apology("Username already exists")

        # Remember the logged in user with session
        session["user_id"] = new_user

        # Redirect user to homepage
        return redirect("/")

    # User reached route via GET (via Clicking a link or redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # User reached route via GET (via Clicking a link or redirect)
    if request.method == "GET":

        user_id = session["user_id"]
        symbols_user = db.execute("SELECT symbol FROM transactions WHERE user_id = ? GROUP BY symbol HAVING SUM(shares) > 0", user_id)
        return render_template("sell.html", symbols = row["symbol"] for row in symbols_user)

    # Update users and transactions table via updates from users via POST
    else:
        # Casting done to convert shares to int type although form is type number
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        # Ensure symbol field is not blank and symbol exists in database
        if not symbol:
            return apology("Must input symbol, 403")

        # Get corresponding stock data from API. Input symbol all convert to uppercase
        stock_data = lookup(symbol.upper())

        if stock_data == None:
            return apology("Symbol not exist")

        # Ensure input shares is a positive integer
        if shares < 0:
            return apology("Input shares figure must be positive")

        # Get current stock pricing value. Stock_data["price"] dict value already casted into float value
        transaction_value = shares * stock_data["price"]

        # Get user ID from session
        user_id = session["user_id"]

        # Get cash value of user using obtained ID
        user_cashdict = db.execute("SELECT cash FROM users WHERE id = ?", user_id)

        # Ensure correct return json data: return jsonify(user_cashdict)
        # To obtain only the cash value figure from the cash dictionary. There is only 1 element for each user
        user_cash = user_cashdict[0]["cash"]

        # Obtain shares that user owned
        user_sharesdict = db.execute("SELECT SUM(shares) AS shares FROM transactions WHERE user_id = ? AND symbol = ?", user_id, symbol)
        user_shares = user_sharesdict[0]["shares"]

        # Evaluate if user owned sufficient shares as input
        if shares > user_shares:
            return apology("Insufficient shares owned")

        # Remaining cash value after selling stocks
        rem_cash = user_cash + transaction_value

        # Update cash data in table with remaining cash after selling stock
        db.execute("UPDATE users SET cash = ? WHERE id = ?", rem_cash, user_id)

        # Obtain current datetime when user place order to buy stock
        date = datetime.datetime.now()

        # Insert obtained info into transactions table. (-1)* shares since we want to decrease no. of shares with input accordingly
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES(?, ?, ?, ?, ?)", user_id, stock_data["symbol"], (-1)*shares, stock_data["price"], date)

        # Display a message
        flash("Successfully sold shares!")

        # Redirect user to homepage
        return redirect("/")
