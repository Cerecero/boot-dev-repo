def find_max(nums):
    if not nums:
        return None
    minimum = float("-inf")
    for num in nums:
        if num > minimum:
            minimum = num
    return minimum

