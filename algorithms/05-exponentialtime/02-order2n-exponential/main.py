def power_set(input_set):
    if not input_set:
        return [[]]

    subset_without_first = power_set(input_set[1:])
    subset = []

    for sub in subset_without_first:
        subset.append(sub)
        subset.append([input_set[0]] + sub)
    return subset
