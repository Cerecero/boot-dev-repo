import math


def prime_factors(n):
    prime_factor_list = []
    while n % 2 == 0:
        prime_factor_list.append(2)
        n = n//2

    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            prime_factor_list.append(i)
            n = n // i
    if n > 2:
        prime_factor_list.append(n)
    return prime_factor_list
