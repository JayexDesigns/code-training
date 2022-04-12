import sys
import math

w, h = [int(i) for i in input().split()]
n = int(input())
x0, y0 = [int(i) for i in input().split()]

possibleWidth = list(range(w))
possibleHeight = list(range(h))
currentPosX = x0
currentPosY = y0

while True:
    bomb_dir = input()

    if "L" in bomb_dir:
        possibleWidth = possibleWidth[0:possibleWidth.index(currentPosX)]
        currentPosX = possibleWidth[len(possibleWidth)//2]
    elif "R" in bomb_dir:
        possibleWidth = possibleWidth[possibleWidth.index(currentPosX)+1:]
        currentPosX = possibleWidth[len(possibleWidth)//2]

    if "U" in bomb_dir:
        possibleHeight = possibleHeight[0:possibleHeight.index(currentPosY)]
        currentPosY = possibleHeight[len(possibleHeight)//2]
    elif "D" in bomb_dir:
        possibleHeight = possibleHeight[possibleHeight.index(currentPosY)+1:]
        currentPosY = possibleHeight[len(possibleHeight)//2]

    print(f"{currentPosX} {currentPosY}")
