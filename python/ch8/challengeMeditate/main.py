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

# Assignment
# Complete the meditate function using a while loop. It takes mana, max_mana,
# energy and energy_potions integers.

# While meditating, a character converts 1 energy into up to 3 mana for each iteration of the loop.
# mana cannot exceed the max_mana.
# If they have any energy_potions when they run out of energy,
# they will use 1 energy potion to gain 50 energy and continue meditating.
# A character will stop meditating if either:
# Their mana reaches the max_mana, or
# They run out of energy and energy_potions.
# Return the mana and remaining energy and energy_potions when the character stops meditating.
#
# Tip
# Don't forget! A character cannot have more mana than their max_mana threshold.
# Be sure to handle cases where meditate raises their mana above their max.

# 1 ENERGY = 3 Mana
# MANA Cannot exceed MAX MANA
# 1 ENERGY POTION = 50 ENERGY


# While the player still has energy AND they have potions AND mana  is not max mana
#       add 3 mana
#       if energy is 0
    # use an energy potion
#       deduce energy -1
#
#
