"""
GAPFUL NUMBERS
- 3 DIGITS NUMBER
- DIVISIBLE BY THE FIRST AND LAST NUMBERS TOGUETHER
"""

def is_gapful(number):
    if len(str(number)) == 3:
        first = int(str(number)[0])
        second = int(str(number)[2])
        if number % int(str(first) + str(second)) == 0:
            return "This number is a gapful number"
        else:
            return "This number is not a gapful number"
    else:
        return "This number doesn't have 3 digits"

while True:
    number = ""
    while type(number) != int:
        number = input("Input a number that has 3 digits: ")
        try:
            number = int(number)
        except:
            print("That's not a number")
            continue
    print(is_gapful(number))