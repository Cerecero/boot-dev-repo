def get_num_guesses(length):
    if length == 1:
        return 26
    combinations = 0
    for i in range(1, length + 1):
        combinations += 26 ** i

    return combinations
