def find_min(nums):
    min = float("inf")
    for num in nums:
        if num < min:
            min = num
        print(min)
    return min

nums = [1, 3, -1, 2]
find_min(nums)

