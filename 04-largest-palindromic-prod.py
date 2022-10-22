"""
A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.

Find the largest palindrome made from the product of two 3-digit numbers.
"""

def palindrome(n):
    return int(str(n) + str(n)[::-1])

def is_product(n):
    for i in range(1000, 100, -1):
        if (n % i == 0) and (n / i < 1000):
            return True

g = (i for i in range(999, 100, -1) if is_product(palindrome(i)))
print(palindrome(next(g)))