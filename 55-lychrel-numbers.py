"""
How many Lychrel numbers are there below ten-thousand?
"""

MAX = 10_000

def is_palindrome(n):
    n = str(n)
    firstPart = n[:len(n)//2]
    lastPart = n[len(n)//2:]
    if len(n) % 2:
        lastPart = lastPart[1:]
    return firstPart == lastPart[::-1]

def is_lyrchrel(n):
    for _ in range(50):
        n = n + int(str(n)[::-1])
        if is_palindrome(n):
            return False
    return True

print(len([n for n in range(1, MAX) if is_lyrchrel(n)]))