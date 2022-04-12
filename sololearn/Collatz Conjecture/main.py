"""
COLLATZ CONJECTURE
- GIVEN A NUMBER IT IS DIVIDED BY 2 IF IT IS EVEN AND MULTIPLIED BY THREE AND ONE IS ADDED IF IT IS ODD
- THE STEP ABOVE IS REPEATED UNTIL THE SEQUENCE ARRIVES TO 1
- ALL THE SEQUENCE MUST BE PRINTED
"""

def sequence(number):
    while number > 1:
        if number % 2 == 0:
            print(f"{number} / 2 = {number // 2}")
            number = number // 2
        else:
            print(f"{number} x 3 + 1 = {number * 3 + 1}")
            number = number * 3 + 1

while True:
    number = ""
    while type(number) != int:
        number = input("Input a number: ")
        try:
            number = int(number)
        except:
            print("That's not a number")
            continue
    sequence(number)