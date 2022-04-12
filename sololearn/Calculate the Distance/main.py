"""
CALCULATE THE DISTANCE
- CALCULATE THE DISTANCE BETWEEN TWO POINTS IN THE X AND Y AXES
"""

from math import sqrt

def distance(point1x, point1y, point2x, point2y):
    return abs(sqrt((point2x - point1x)**2 + (point2y - point1y)**2))

while True:
    points = []
    for i in "xyxy":
        while True:
            point = input(f"Enter the {i} value of a point: ")
            try:
                point = int(point)
                points.append(point)
                break
            except:
                print("That is not a valid value")
    print(f"The distance between those points is {distance(points[0], points[1], points[2], points[3])}")