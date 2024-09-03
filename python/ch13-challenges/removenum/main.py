def remove_nonints(nums):
    integerList = []
    for num in nums:
        if type(num) == int:
            integerList.append(num)
    return integerList
