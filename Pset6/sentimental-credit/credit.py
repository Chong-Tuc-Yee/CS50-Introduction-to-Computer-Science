from cs50 import get_int

# TODO: Request user input credit card number and print out number if valid
def main():

    # Ensure correct usage
    while True:
        ccn_number = get_int("Number: ")
        if ccn_number >= 0:
            break

    if validity(ccn_number):
        print_ccn(ccn_number)
    else:
        print("Invalid")


# Check validity for credit card number
def validity(ccn_number):
    ccn_length = check_length(ccn_number)
    return (ccn_length == 13 or ccn_length == 15 or ccn_length == 16) and check_sum(ccn_number)


# Obtain number of digits for credit card number
def check_length(ccn_number):
    dlen = 0
    for dlen in range(len(str(ccn_number))):
        dlen += 1
    return dlen


# Perform Luhn's algorithm to check validity
def check_sum(ccn_number):
    sum = 0
    # ccn changed to string format to obtain number of digits of card
    # i gets range from 0 to length of str -1
    for i in range(len(str(ccn_number))):
        if (i % 2 == 0):
            sum += ccn_number % 10
        else:
            doub = 2 * (ccn_number % 10)
            # Integer division operator // used to obtain first digit of number eg. 16= 1+6
            sum += (doub // 10) + (doub % 10)
        # Reduce length of ccn_number. Range of i is not recomputed.
        ccn_number //= 10
    return sum % 10 == 0    


# Evaluate type of credit card for input card number and display type
def print_ccn(ccn_number):
    if (ccn_number >= 34e13 and ccn_number < 35e13) or (ccn_number >= 37e13 and ccn_number < 38e13):
        print("AMEX")
    elif ccn_number >= 51e14 and ccn_number < 56e14:
        print("MASTERCARD")
    elif (ccn_number >= 4e12 and ccn_number < 5e12) or (ccn_number >= 4e15 and ccn_number < 5e15):
        print("VISA")
    else:
        print("INVALID")


# Python's way of calling main function after user-defined functions
if __name__ == "__main__":
    main()
