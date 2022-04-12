import sys
import math

n = int(input())
lowest = None
for i in input().split():
    t = int(i)
    if lowest == None or abs(lowest) > abs(t):
        lowest = t
    elif abs(lowest) == abs(t):
        if (lowest < 0):
            lowest = t

if lowest == None:
    lowest = 0

print(lowest)
