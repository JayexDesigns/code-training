"""
LINEAR EQUATION SOLVER
- GIVEN A LINEAR EQUATION SOLVE IT AUTOMATICALLY
"""

def solver(inc, num1, num2):
    return (num2 - num1)/inc

while True:
    print("\nEnter a linear equation, ex: 2x - 3 = 1")
    valid = False
    while valid == False:
        entry = input("-> ")
        try:
            inc, op, num1, eq, num2 = entry.split(" ")
            num1 = int(op + num1)
            num2 = int(num2)
            inc, x = inc.split("x")
            inc = int(inc)
            valid = True
        except:
            print("That's not a valid entry, make sure you separate each element with a space")
    print(f"   x = {solver(inc, num1, num2)}")