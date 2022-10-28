"""
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, 
but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
"""

from itertools import count

for x in count(123456):
    found = True
    xSet = set(str(x))
    for m in range(6, 0, -1):
        if xSet != set(str(x*m)):
            found = False
            break
    if found:
        print(x)
        break