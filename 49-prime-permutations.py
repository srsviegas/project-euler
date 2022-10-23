"""
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, 
is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit
 numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, 
but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?
"""

from itertools import permutations, product
from sympy import sieve

MIN, MAX = 1000, 10000

primes = set(sieve.primerange(MIN, MAX))
seen = set()

for i in primes:
    # Skip number if it was already seen in a permutation list
    if i in seen: continue
    # Generates all prime permutations of the number
    perm = set(int(''.join(p)) for p in permutations(str(i)) if int(''.join(p)) in primes)
    if (len(perm) > 2):
        for a, b in product(perm, perm):
            if (a < b) and (b + (b - a) in perm):
                print([a, b, b + b - a], str(a)+str(b)+str(2*b-a))
    seen = seen.union(perm)