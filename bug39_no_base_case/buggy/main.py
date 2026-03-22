def infinite_recursion(n):

    return n + infinite_recursion(n - 1)

print(infinite_recursion(10))
