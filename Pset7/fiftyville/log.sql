-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Identify the date, time, location and description of the particular crime from reports.
-- Found out that the theft occurred on 2021/7/28 1015am on Humphrey Street bakery (Bakery mentioned in interview transcripts).
SELECT * FROM crime_scene_reports;

-- Find matching descriptions from interview transcripts to gain more info.
-- Witness 1: Ruth suggests checking security footage of thief leaving within 10 mins after crime admitted whereby enables us to obtain car license plate of the theif's car.
-- Witness 2: Eugene recognized the thief and mentioned bakery's name as Emma's bakery and saw thief withdraw money from ATM on Leggett Street that morning.
-- Witness 3: Raymond overheard a call from thief which was less than a minute that they planned to leave Fiftyville on earliest flight tomorrow and asked to purchase flight ticket.
SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE "%bakery%";

-- To narrow down the list of license plate of suspect car
-- Possible car license plate is 5P2BI95, 94KL13X, 6P58WS2, 4328GD8, G412CB7, L93JTIZ, 322W7JE, 0NTHK55.
SELECT license_plate, activity, hour, minute FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25;

-- To narrow down the list of account number of suspect
-- Possible account number is 28500762, 28296815, 76054385, 49610011, 16153065, 25506511, 81061156, 26013199.
SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location LIKE "%Leggett Street%" AND transaction_type LIKE "%Withdraw%";

-- Obtain list of suspects where account number and license plate match record according to descriptions given by witness.
-- A total of 4 suspects was narrowed down to: Bruce, Diana, Iman, Luca.
SELECT * FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number IN (
    SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location LIKE "%Leggett Street%" AND transaction_type LIKE "%Withdraw%"
)
AND license_plate IN(
    SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25
);

-- To check the phone call with matching dates and duration and match them with the list of 4 suspects from above.
-- The matching suspects are only 2: Bruce and Diana
SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

-- Find out matching suspect who booked earliest flight on next day 29/7/2021 and have matching passport number from search results of bank accounts
-- Passport number 5773159633 matches to Bruce.
-- Bruce planned to travel to New York City from Fiftyville.
SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id
JOIN airports ON flights.destination_airport_id =  airports.id
WHERE year = 2021 AND month = 7 AND day = 29
AND passport_number = (
    SELECT passport_number FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id
    WHERE account_number IN (
        SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location LIKE "%Leggett Street%" AND transaction_type LIKE "%Withdraw%"
    )
    AND license_plate IN (
        SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute <= 25
    )
);

-- To find out accomplice
-- Found result is Robin
SELECT name FROM people WHERE phone_number = (
    SELECT receiver FROM phone_calls
    WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 AND caller = "(367) 555-5533"
);
