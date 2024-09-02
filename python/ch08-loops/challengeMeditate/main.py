def meditate(mana, max_mana, energy, energy_potions):
    while mana < max_mana:
        if energy <= 0:
            if energy_potions > 0:
                energy += 50
                energy_potions -= 1
            else:
                break
        if mana + 3 <= max_mana:
            mana += 3
        else:
            mana = max_mana

        energy -= 1
    return mana, energy, energy_potions
