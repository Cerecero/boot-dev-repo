def median_followers(nums):
    if not nums:
        return None
    
    sorted_list = sorted(nums)
    length_list = len(sorted_list)
    median = 0
    if length_list % 2 == 0:
        middle_index = sorted_list[length_list // 2 - 1]
        middle_index2 = sorted_list[length_list // 2]
        median = (middle_index + middle_index2) /2
    else:
        index = int((len(sorted_list)/2))
        median = sorted_list[index]
    return median
