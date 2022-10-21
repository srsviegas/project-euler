""" 
The first two consecutive numbers to have two distinct prime factors are:
    14 = 2 * 7
    15 = 3 * 5

The first three consecutive numbers to have three distinct prime factors are:
    644 = 2² * 7 * 23
    645 = 3 * 5 * 43
    646 = 2 * 17 * 19

Find the first four consecutive integers to have four distinct prime factors each. 
What is the first of these numbers? 
"""

from math import floor, sqrt
from time import time
start_t = time()

# Number of consecutive numbers / prime factors
N = 4

def is_prime(n):
    if (n == 2) or (n == 3):
        return True
    if (n % 2 == 0) or (n % 3 == 0):
        return False
    for i in range(5, floor(sqrt(n)+1), 6):
        if (n % i == 0) or (n % (i+2) == 0):
            return False
    return True

def factors(n):
    factors = 0
    i = 2
    while (n != 1):
        if is_prime(n):
            return factors+1
        if (n % i == 0):
            factors += 1
            while (n % i == 0):
                n /= i
        i += 1
    return factors

n = 2
consecutives = 0
while (consecutives < N):
    if factors(n) == N:
        consecutives += 1
    else: consecutives = 0
    n += 1
print(n-N)

print("\ntime elapsed:", time() - start_t)
