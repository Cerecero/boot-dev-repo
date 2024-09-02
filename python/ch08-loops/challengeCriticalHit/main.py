def calculate_flurry_crit(num_attacks, base_damage):
    total_damage = 0
    for i in range(1, num_attacks + 1):
        if i == num_attacks:
            total_damage += base_damage * 4
        else:
            total_damage += base_damage * 2

    return total_damage
