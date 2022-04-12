"""
PRIME STRINGS
- CHECK IF A STRING CAN BE CREATED BY A COMBINATION OF EQUAL STRINGS
"""

def prime(string):
    if len(string) <= 1:
        pass

    else:
        for i in range(len(string)-1):
            num = len(string)-i

            if len(string) % num == 0:
                x = 0
                for a in range(num):
                    op = int(len(string) / num)
                    if string[a * op:a * op + op] == string[0:op]:
                        x += 1

                if x == num:
                    return ""

            else:
                continue

    return "not "

while True:
    entry = input("Enter a string: ")
    print(f"Your string is {prime(entry)}a prime string")