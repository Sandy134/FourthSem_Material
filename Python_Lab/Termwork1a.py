n = int(input("Enter the value of n:"))

primes = [1] * (n+1)
primes[0] = 0  # Neither prime nor composite
primes[1] = 0  # Neither prime nor composite

for i in range(2, (n//2)):
    if primes[i] == 1:
        j = 2
        while j * i <= n:
            primes[j * i] = 0
            j += 1

print(f"All primes from 2 to {n} are:")
for i in range(n):
    if primes[i] == 1:
        print(i, end="\t")
