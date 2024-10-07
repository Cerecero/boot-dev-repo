def count_names(list_of_lists, target_name):
    count = 0
    for sublist in list_of_lists:
        for name in sublist:
            if target_name in name:
                count += 1
    return count

