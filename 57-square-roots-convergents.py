"""
It is possible to show that the square root of two can be expressed as an infinite continued fraction.
In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?
"""

from sympy import Rational
from functools import lru_cache


def d(x):
    return len(str(x))

@lru_cache(maxsize=1000)
def sqrt_two(term):
    if term == 0:
        return Rational('1/2')
    else:
        return 1 / (2 + sqrt_two(term-1))

expansions = [1 + sqrt_two(n) for n in range(1000)]
answer = len(list(filter(lambda x: d(x.numerator) > d(x.denominator), expansions)))
print(answer)