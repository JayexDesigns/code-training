"""
REMOVE SPACES FROM A STRING
- FROM A STRING REMOVE ALL SPACES
"""

from string import whitespace

def remove_spaces(text):
    text = text.replace(" ", "")
    return text

while True:
    text = input("Input your text: ")
    print(remove_spaces(text))