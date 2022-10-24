"""
The palindromic number 595 is interesting because it can be written as the sum of consecutive squares: 
    6^2 + 7^2 + 8^2 + 9^2 + 10^2 + 11^2 + 12^2.

There are exactly eleven palindromes below one-thousand that can be written as consecutive square sums, 
and the sum of these palindromes is 4164. Note that 1 = 0^2 + 1^2 has not been included as this problem is 
concerned with the squares of positive integers.

Find the sum of all the numbers less than 10^8 that are both palindromic and can be written as the sum of 
consecutive squares.
"""

from sympy import sqrt
from time import time
start_t = time()

MAX = 10**8

def is_palindrome(n):
    return (str(n) == str(n)[::-1])

squares = tuple(n*n for n in range(1, int(sqrt(MAX))))

squareSums = []
for i, x in enumerate(squares):
    for y in squares[i+1:]:
        x += y
        if (x > MAX): break
        if (x not in squareSums) and is_palindrome(x):
            squareSums.append(x)

print(sum(squareSums))
print("\ntime elapsed:", time() - start_t)