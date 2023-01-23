import csv
from sys import argv


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        sys.exit("Usage: python dna.py databases/FILENAME sequences/FILENAME")

    # TODO: Read database file into a variable
    #strs = []
    dbfile = open("./" + argv[1])
    dbreader = csv.DictReader(dbfile)
    strs = dbreader.fieldnames[1:]  # Use fieldnames to access all the STRs title columns excluding the first name column

    # TODO: Read DNA sequence file into a variable
    seqfile = open("./" + argv[2])
    seqreader = seqfile.read()
    seqfile.close()

    # TODO: Find longest match of each STR in DNA sequence
    dnaprofile = {}
    for str in strs:
        dnaprofile[str] = consec_repeat(str, seqreader)

    # TODO: Check database for matching profiles
    for row in dbreader:
        if match(strs, dnaprofile, row):
            print(f"{row['name']}")
            dbfile.close()
            return
    # If no match found, print no match and close file
    print("No match")
    dbfile.close()


# Determines the maximum number of consecutive repeats of STRs
def consec_repeat(str, seqreader):
    i = 0
    while str*(i+1) in seqreader:
        i += 1
    return i


# Determines whether dnaprofile matches with row from strs of dbfile
def match(strs, dnaprofile, row):
    for str in strs:
        if dnaprofile[str] != int(row[str]):
            return False
    return True


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
