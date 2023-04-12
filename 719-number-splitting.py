"""
We define an S-number to be a natural number, n, that is a perfect square and its square root
can be obtained by splitting the decimal representation of  into 2 or more numbers then adding
the numbers.

For example, 81 is an S-number because sqrt(81) = 8 + 1.
    * 6724 -> sqrt(6724) = 6 + 72 + 4
    * 8281 -> sqrt(8281) = 8 + 2 + 81 = 82 + 8 + 1
    * 9801 -> sqrt(9801) = 98 + 0 + 1

Further we define T(N) to be the sum of all S-numbers n <= N. You are given T(10^4) = 41333.
Find T(10^12).
"""

from time import time


def is_snum(num, sqrt, accumulator=0):
    if accumulator > sqrt:
        return False
    elif num == '':
        return accumulator == sqrt
    else:
        for i in range(len(num)):
            if is_snum(num[i+1:], sqrt, accumulator + int(num[:i+1])):
                return True
        return False


start_t = time()

snumber_sum = 41333
for n in range(10**2 + 1, 10**6 + 1):
    if (n % 9 <= 1) and is_snum(str(n*n), n):
        print(n*n)
        snumber_sum += (n*n)

print(snumber_sum)

print("\ntime elapsed:", time() - start_t)