from cs50 import get_int

# TODO: Prompt height input from user
while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

# Print out blocks of hashes and spaces
for i in range(height):
    for j in range(height-i-1):
        print(" ", end="")
    for k in range(i+1):
        print("#", end="")
    print("  ", end="")
    for l in range(i+1):
        print("#", end="")
    print()
