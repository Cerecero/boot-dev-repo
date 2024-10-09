def fib(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    parent = 1
    grandparent = 0

    for i in range(1, n):
        current = parent + grandparent
        grandparent = parent
        parent = current

    return parent

    # return fib(n - 1) + fib(n - 2)
