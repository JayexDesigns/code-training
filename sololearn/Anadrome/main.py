"""
ANADROME
- CHECK IF A ANAGRAM OF A STRING CAN BE A PALINDROME
"""

def anadrome(string):
    if len(string) <= 1:
        return "not "
    else:
        if len(string) % 2 == 0:
            for i in range(len(string)):
                if string.count(string[i]) % 2 != 0:
                    return "not "
            return ""
        else:
            x = 0
            letter = ""
            for i in range(len(string)):
                if x == 2:
                    return "not "
                else:
                    if string.count(string[i]) % 2 != 0 and string[i] != letter:
                        x += 1
                        letter = string[i]
            return ""

while True:
    entry = input("Enter a string: ")
    print(f"That string is {anadrome(entry)}an anadrome")