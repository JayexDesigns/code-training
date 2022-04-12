"""
GOLDBACH'S CONJECTURE
- GIVEN AN EVEN NUMBER FIND TWO PRIME NUMBERS THAT ADDED ARE EQUAL
"""

def goldbach(number):
    prime = []
    for i in range(2, number):
        for j in range(2, i):
            if i % j == 0:
                break
        else:
            prime.append(i)

    print("Your entry can be formed by: ")

    for i in prime:
        for j in prime:
            if number - i == j:
                print(str(i) + " + " + str(j))

while True:
    x = 0
    while x == 0:
        entry = input("Enter a even number: ")
        try:
            entry = abs(int(entry))
            if entry % 2 != 0:
                print("That is not an even number")
            else:
                x = 1
        except:
            print("That is not a valid number")

    goldbach(entry)