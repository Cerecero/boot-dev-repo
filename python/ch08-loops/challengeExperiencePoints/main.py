def calculate_experience_points(level):
    xp_needed = 0
    for i in range(1, level):
        xp_needed += i * 5
    return xp_needed
