"""
BASE CONVERTER
- GIVEN A NUMBER AND A BASE COUNT TO THAT NUMBER USING THAT BASE
"""
from string import ascii_lowercase, digits

def converter(number, base):
    result = ""
    while number//base > 0:
        result = (digits + ascii_lowercase)[number % base] + result
        number = number // base
    return (digits + ascii_lowercase)[number] + result

while True:
    valid = False
    while valid == False:
        entry = input("Enter a number and a base: ")
        try:
            number, base = entry.split(" ")
            number = int(number)
            base = int(base)
            if base <= 36 and base > 0:
                valid = True
            else:
                print("The base must be 36 or lower and higher than 0")
        except:
            print("Those are not valid values")
    
    print(f"{number} in base {base} is expressed as {converter(number, base)}")