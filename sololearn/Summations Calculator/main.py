"""
SUMMATIONS CALCULATOR
- 3 INPUTS
- LOWER BOUND, UPPER BOUND & EXPRESSION
"""

def summations_calculator(lower, upper, expression, number):
    result = 0

    if expression == "+":
        for i in range(lower, upper):
            result = result + i + number
        return result

    elif expression == "-":
        for i in range(lower, upper):
            result = result + i - number
        return result

    elif expression == "*":
        for i in range(lower, upper):
            result = result + i * number
        return result

    elif expression == "/":
        for i in range(lower, upper):
            result = result + i / number
        return result

    elif expression == "**":
        for i in range(lower, upper):
            result = result + i ** number
        return result

    elif expression == "//":
        for i in range(lower, upper):
            result = result + i // number
        return result

    elif expression == "%":
        for i in range(lower, upper):
            result = result + i % number
        return result

    else:
        return "The structure must be: [lower] [upper] [expression]"


while True:
    try:
        entry = input("Enter your summations: ")
        lower, upper, expression = entry.split(" ")
        lower = int(lower)
        upper = int(upper) + 1
        number = int(expression[1:])
        expression = expression[0]
        print(f"the result is: {summations_calculator(lower, upper, expression, number)}")

    except:
        try:
            lower, upper, expression = entry.split(" ")
            lower = int(lower)
            upper = int(upper)
            number = int(expression[2:])
            expression = expression[0:2]
            print(f"the result is: {summations_calculator(lower, upper, expression, number)}")

        except:
            print("The structure must be: [lower] [upper] [expression]")