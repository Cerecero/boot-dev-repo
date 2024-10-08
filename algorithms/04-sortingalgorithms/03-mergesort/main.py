def merge_sort(nums):
    if len(nums) < 2:
        return nums
    half = len(nums)//2
    first_half = nums[:half]
    second_half = nums[half:]
    sorted_left = merge_sort(first_half)
    sorted_right = merge_sort(second_half)
    return merge(sorted_left, sorted_right)


def merge(first, second):
    result = []
    i = j = 0

    while i < len(first) and j < len(second):
        if first[i] <= second[j]:
            result.append(first[i])
            i += 1
        else:
            result.append(second[j])
            j += 1

    result.extend(first[i:])
    result.extend(second[j:])

    return result
