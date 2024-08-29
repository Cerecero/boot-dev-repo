def find_max(nums):
    max_so_far = float("-inf")
    # Chat GPT
    for num in nums:
        if num > max_so_far:
            max_so_far = num
    return max_so_far


# My Answer
#    if not nums:
#        return max_so_far
#    else:
#        max = nums[0]
#        for i in range(0, len(nums)):
#            if nums[i] > max:
#                max = nums[i]
#    return max
