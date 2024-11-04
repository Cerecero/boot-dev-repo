def fight_soldiers(soldier_one, soldier_two):
    if get_soldier_dps(soldier_one) > get_soldier_dps(soldier_two):
        return "soldier 1 wins"
    if get_soldier_dps(soldier_two) > get_soldier_dps(soldier_one):
        return "soldier 2 wins"
    return "both soldiers die"
def get_soldier_dps(soldier):
    soldierDPS = soldier["damage"] * soldier["attacks_per_second"]
    return soldierDPS

