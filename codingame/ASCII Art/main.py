import sys
import math

l = int(input())
h = int(input())
t = input()
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '?']
text = ""


for i in range(h):
    row = input()
    for j in t:
        try:
            char = letters.index(j.lower())*l
        except:
            j = "?"
            char = letters.index(j.lower())*l
        text += row[char:char+l]
    text += "\n"

print(text)
