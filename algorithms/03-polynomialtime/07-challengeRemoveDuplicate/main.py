def remove_duplicates(nums):
    rm_dup = []
    for num in nums:
        if num not in rm_dup:
            rm_dup.append(num)
    return rm_dup
