"""
Both 169 and 961 are the square of a prime. 169 is the reverse of 961.

We call a number a reversible prime square if:
1. It is not a palindrome, and
2. It is the square of a prime, and
3. Its reverse is also the square of a prime.

169 and 961 are not palindromes, so both are reversible prime squares.

Find the sum of the first 50 reversible prime squares.
"""

from math import sqrt
from sympy import sieve
from time import time
start_t = time()

def reversed_int(x):
    return int(str(x)[::-1])

def sqrt_prime(x):
    x = sqrt(x)
    if x != int(x):
        return False
    return int(x) in sieve
    
counter, solution = 0, 0
for x in sieve:
    x = x*x
    r = reversed_int(x)
    if x != r and sqrt_prime(r):
        counter += 1
        solution += x
    if (counter >= 50):
        print(solution)
        break

print("\ntime elapsed:", time() - start_t)