def bubble_sort(nums):
    list_sorted = nums # Could of used the same nums list
    swapping = True
    end = len(nums)

    while swapping:
        swapping = False
        for i in range(1, end):
            if list_sorted[i-1] > list_sorted[i]:
                list_sorted[i-1], list_sorted[i] = list_sorted[i], list_sorted[i-1]
                swapping = True
        end -= 1
    return list_sorted
