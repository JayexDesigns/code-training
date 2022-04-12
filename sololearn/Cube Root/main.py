"""
CUBE ROOT
- FIND THE CUBE ROOT OF A NUMBER WITHOUT USING LIBRARIES
- PRECISION OF 0.0001
"""

def finder(initial, number):
    for i in range(100000):
        num = (2 * initial + number / initial ** 2) / 3
        if abs(num - initial) < 0.0001:
            return num
        else:
            initial = num

while True:
    x = 0
    while x == 0:
        entry = input("Enter a number: ")
        try:
            entry = float(entry)
            x = 1
        except:
            print("That is not a number")
    print(f"The square root of {entry} is {round(finder(entry/3, entry), 4)}")