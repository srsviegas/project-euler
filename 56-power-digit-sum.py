"""
A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost 
unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the 
digits in each number is only 1.

Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?
"""

from functools import reduce
from itertools import product

def digit_sum(n):
    n = str(n)
    return reduce(lambda x, y: int(x) + int(y), n)

powerDS = [[digit_sum(a**b), a, b] for a, b in product(range(4, 100), range(4, 100))]
print(max(powerDS, key=lambda x: x[0]))