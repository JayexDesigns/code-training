import sys
import math

message = input()

barray = bytearray(message, "utf8")
binary = ''
for i in barray:
    i = bin(i)[2:]
    binary += "{:0>7s}".format(i)

encodedMessage = ''
last = None
for i in binary:
    if last == i:
        encodedMessage += "0"
    else:
        if last != None:
            encodedMessage += " "

        if i == "1":
            encodedMessage += "0 0"
        else:
            encodedMessage += "00 0"
        last = i

print(encodedMessage)
