"""
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
"""

from math import sqrt

def is_prime(n):
    if (n % 2 == 0) or (n % 3 == 0):
        return 0
    for i in range(5, int(sqrt(n)+1), 6):
        if (n % i == 0) or (n % (i+2) == 0):
            return 0
    return 1

n, count = 5, 3
while (count < 10_001):
    n += 2
    if (is_prime(n)):
        count += 1

print(n)