def factorial(num):
    factor = 1
    if num == 0:
        return 1
    for i in range(1, num+1):
        factor *= i
    return factor
