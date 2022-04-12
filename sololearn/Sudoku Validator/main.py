"""
SUDOKU VALIDATOR
- GIVEN A SOLVED SUDOKU CHECK IF IT'S CORRECT
"""

def validator(sudoku):
    # CHECK ALL ROWS
    for i in sudoku:
        row = 0
        for j in i:
            row += j
        if row != 45:
            return "not valid"

    # CHECK ALL COLUMNS
    for i in range(9):
        column = 0
        for j in sudoku:
            column += j[i]
        if column != 45:
            return "not valid"

    # CHECK SQUARES
    for a in range(3):
        for b in range(3):
            square = 0
            for i in range(3):
                for j in range(3):
                    square += (sudoku[i+a*3])[j+b*3]
            if square != 45:
                return "not valid"

    return "valid"

while True:
    print("\nEnter each row of a sudoku with this format: 1 3 9 2 7 5 8 6 4")
    sudoku = []
    for _ in range(9):
        valid = False
        while valid == False:
            entry = input("-> ")
            try:
                row = entry.split(" ")
                if len(row) != 9:
                    print("A row must have 9 numbers")
                    valid = False
                else:
                    for i in range(len(row)):
                        if int(row[i]) <= 9 and int(row[i]) >= 1:
                            row[i] = int(row[i])
                        else:
                            print("The values must be between 1 and 9")
                            valid = False
                            break
                    valid = True
            except:
                print("That row is not valid, make sure it has 9 values between 1 and 9")
        sudoku.append(row)
    print(f"\nYour sudoku is {validator(sudoku)}")