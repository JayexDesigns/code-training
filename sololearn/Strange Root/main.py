"""
STRANGE ROOT
- CHECK IF A CHARACTER OF THE SQUARE ROOT OF A NUMBER EXISTS ON THE SQUARE OF THE SAME NUMBER
- ROUND THE SQUARE ROOT TO ONLY 3 DECIMALS
"""

from math import sqrt

def strange(number):
    square = str(number ** 2)
    square_root = str(round(sqrt(number),3))
    for i in square:
        if i in square_root:
            return "has"
    return "does not have"

while True:
    x = 0
    while x == 0:
        entry = input("Enter a number: ")
        try:
            entry = int(entry)
            x = 1
        except:
            print("That is not a number")
    print(f"The number {strange(entry)} a strange root")