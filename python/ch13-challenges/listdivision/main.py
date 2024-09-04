def divide_list(nums, divisor):
    value = []
    for num in nums:
        print(f"num: {num/divisor}")
        value.append(num/divisor)
        # value += num/divisor
    return value
