"""
LAB NUMBERS
- GIVEN A NUMBER RETURN TRUE IF ONE OF IT'S PRIME DIVISORS, IT'S SQUARE IS ALSO A DIVISOR OF THE NUMBER GIVEN
"""

def lab(number):
    prime = []
    for i in range(2, number):
        for j in range(2, i):
            if i % j == 0:
                break
        else:
            prime.append(i)

    for i in prime:
        if number % i == 0:
            if number % (i**2) == 0:
                return ""

    return "not "

while True:
    valid = False
    while valid == False:
        entry = input("Enter a number: ")
        try:
            entry = int(entry)
            valid = True
        except:
            print("That is not a valid entry")
    print(f"{entry} is {lab(entry)}a lab number")