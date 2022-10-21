from time import time

start_t = time()

s = sum(i**i for i in range(1, 1000))
print(str(s)[-10:])

print("\ntime elapsed:", time() - start_t)