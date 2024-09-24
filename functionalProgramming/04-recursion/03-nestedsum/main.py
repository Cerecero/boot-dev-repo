def sum_nested_list(lst):
    total_size = 0
    for i in lst:
        if isinstance(i, int):
            total_size += i
        if isinstance(i, list):
            total_size += sum_nested_list(i)
    return total_size

