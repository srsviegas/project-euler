"""
A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR
eachbyte with a given value, taken from a secret key. The advantage with the XOR function
is that using the same encryption key on the cipher text, restores the plain text; for
example, 65 XOR 42 = 107, then 107 XOR 42 = 65.

The encryption key consists of three lower case characters. Using 059-cipher.txt, a file
containing the encrypted ASCII codes, and the knowledge that the plain text must contain
common English words, decrypt the message and find the sum of the ASCII values in the
original text.
"""


from itertools import cycle, product


def try_key(key, ciphertext):
    key = cycle(ord(c) for c in key)
    score = 0
    for i, char in enumerate(ciphertext):
        char = chr(char ^ next(key))
        if not char.isprintable():
            return (False, i % 3)
        elif char.isalpha():
            score += 2
        elif char.isdigit():
            score += 1
    return (True, score)


def decipher(key, ciphertext):
    plaintext = str()
    key = cycle(ord(c) for c in key)
    for char in ciphertext:
        plaintext += chr(char ^ next(key))
    return plaintext


if __name__ == "__main__":
    with open("059-cipher.txt", "r") as file:
        ciphertext = list(int(c) for c in file.readline().split(','))

    possible_keys = product('abcdefghijklmnopqrstuvwxyz', repeat=3)

    functionable_keys = []
    invalid_chars = [[], [], []]

    for key in possible_keys:
        if (key[0] in invalid_chars[0] or
            key[1] in invalid_chars[1] or
            key[2] in invalid_chars[2]):
            continue
        outcome = try_key(key, ciphertext)
        if outcome[0]:
            functionable_keys.append((key, outcome[1]))
        else:
            invalid_chars[outcome[1]].append(key[outcome[1]])

    correct_key = max(functionable_keys, key=lambda k: k[1])[0]
    plaintext = decipher(correct_key, ciphertext)
    ascii_sum = sum(ord(c) for c in plaintext)

    print(f'key: "{"".join(correct_key)}" \n\n{plaintext}\n')
    print(f'answer: {ascii_sum}')