def process_list(items):
    processed = []
    for i in range(len(items)):
        processed.append(items[i] * 2)
    return processed[4]

print(process_list([1, 2, 3, 4, 5, 6]))
