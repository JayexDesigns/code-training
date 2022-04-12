"""
PASSWORD VALIDATOR:
- AT LEAST 5 CHARACTERS
- NO MORE THAN 10 CHARACTERS
- AT LEAST 1 SPECIAL CHARACTER AND A NUMBER
- NO SPACES
"""

from string import punctuation, digits, whitespace

def password_validator(password):
    if len(password) <= 10 and len(password) >= 5:
        for i in punctuation:
            if i in password:
                for i in digits:
                    if i in password:
                        for i in whitespace:
                            if i not in password and " " not in password:
                                return ""
    return "not "

while True:
    password = input("Input a password: ")
    print(f"Your password is {password_validator(password)}valid")