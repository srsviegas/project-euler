"""
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
"""

from math import sqrt

def is_prime(n):
    if (n % 2 == 0) or (n % 3 == 0):
        return 0
    for i in range(5, int(sqrt(n)+1), 6):
        if (n % i == 0) or (n % (i+2) == 0):
            return 0
    return 1

def largest_factor(n):
    sqroot = int(sqrt(n))
    if (sqroot % 2 == 0) : sqroot -= 1
    for i in range(sqroot, 2, -2):
        if (n % i == 0) and (is_prime(i)):
            return i

print(largest_factor(600851475143))