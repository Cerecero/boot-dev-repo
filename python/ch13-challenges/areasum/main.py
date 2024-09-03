def area_sum(rectangles):
    sum = 0
    for rectangle in rectangles:
        sum += rectangle['height'] * rectangle['width']
    return sum
