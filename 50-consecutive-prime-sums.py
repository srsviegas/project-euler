"""
The prime 41, can be written as the sum of six consecutive primes:
    41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
"""

from math import floor, sqrt
from time import time

s_time = time()

MAX = 1_000_000

def is_prime(n):
    if (n % 2 == 0) or (n % 3 == 0):
        return False
    for i in range(5, floor(sqrt(n)+1), 6):
        if (n % i == 0) or (n % (i+2) == 0):
            return False
    return True

primes = (2, 3) + tuple(p for p in range(5, MAX, 2) if is_prime(p))

consec, ans = 21, 0
for i in range(len(primes)):
    for j in range(i+consec, len(primes)):
        s = sum(primes[i:j])
        if (s > MAX):
            break
        elif (s in primes):
            consec = j - i
            ans = s

print(ans, consec)
print("time elapsed:", time() - s_time)