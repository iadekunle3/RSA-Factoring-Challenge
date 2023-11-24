#!/usr/bin/python3
import sys

def factorize(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return i, n // i
    return n, 1

def main():
    with open(sys.argv[1], 'r') as file:
        numbers = file.read().splitlines()
    for number in numbers:
        p, q = factorize(int(number))
        print(f"{number}={p}*{q}")

if __name__ == "__main__":
    main()
