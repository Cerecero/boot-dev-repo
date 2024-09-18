def get_median_font_size(font_sizes):
    if not font_sizes:
        return
    sorted_sized = sorted(font_sizes)

    mid_index = len(sorted_sized) // 2
    print(f"This is mid_index {mid_index}")
    return sorted_sized[mid_index]

