"""
The sum of the squares of the first ten natural numbers is,
    1² + 2² + ... + 10² = 385
The square of the sum of the first ten natural numbers is,
    (1 + 2 + ... + 10)² = 55² = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
    3025 - 385 = 2640

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
"""

MAX = 100

squareOfSum = sum(x for x in range(1, MAX+1))**2
sumOfSquares = sum(x**2 for x in range(1, MAX+1))

print(squareOfSum, "-", sumOfSquares, "=", squareOfSum - sumOfSquares)