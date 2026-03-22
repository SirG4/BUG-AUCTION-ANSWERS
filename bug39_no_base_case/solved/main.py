def infinite_recursion(n):
    if n <= 0: # correct part
        return 0 # correct part
    return n + infinite_recursion(n - 1)

print(infinite_recursion(10))
