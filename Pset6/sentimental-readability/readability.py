from cs50 import get_string

# TODO
def main():

    # Get input from user
    text = get_string("Text: ").strip()
    L = count_letters(text) / count_words(text) * 100
    S = count_sentences(text) / count_words(text) * 100
    A = count_words(text)
    # Compute Coleman-Liau index
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


# Count no. of letters
def count_letters(text):
    num_letters = 0

    for i in range(len(text)):
        if text[i].isalpha():
            num_letters += 1

    return num_letters


# Count no. of words
def count_words(text):
    num_words = 0

    for j in range(len(text)):
        # Check condition where first character is not blank space and condition where no adjacent spacing
        # Need to include j == 0 as we only want pass this condition once for the loop and we need to include back the first word which is omitted during the second condition
        # No need to consider j == len(text)-1 during second condition where last character may be blank space as return from len(text) will exclude it
        if (j == 0 and text[j] != ' ') or (text[j] == ' ' and text[j + 1] != ' '):
                num_words += 1
        elif text[j] == '-':
                num_words

    return num_words


# Count no. of sentences
def count_sentences(text):
    num_sentences = 0

    for k in range(len(text)):
        if text[k] == '.' or text[k] == '!' or text[k] == '?':
            num_sentences += 1

    return num_sentences


# Python's way of calling main function after user defined function
if __name__ == "__main__":
    main()
