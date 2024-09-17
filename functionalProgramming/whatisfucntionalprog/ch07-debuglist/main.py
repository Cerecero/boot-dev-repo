def deduplicate_lists(lst1, lst2, reverse=False):
    combined_set = set(lst1 + lst2)

    return sorted(combined_set, reverse=reverse)
    # combined = lst1 + lst2
    #
    # return_list = []
    # for item in combined:
    #     if item not in return_list:
    #         return_list.append(item)
    #
    # if reverse == True:

        # if reverse == True:
        #     reverse_sorted_list = []
        #     for item in lst1 + lst2:
        #         if item not in reverse_sorted_list:
        #             reverse_sorted_list.append(item)
        #     return sorted(reverse_sorted_list, reverse=True)
        # output = []
        # for item in lst1+lst2:
        #     if item not in output:
        #         output.append(item)
        # return output
