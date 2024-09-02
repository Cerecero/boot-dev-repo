def remove_duplicates(spells):
    if not spells:
        return spells
    set_spells = set()
    list_spells = []
    for spell in spells:
        set_spells.add(spell)
    list_spells += set_spells
    return list_spells
# Assignment
# Complete the remove_duplicates function. 
# It should take a list of spells that a player has learned and return a new
# List where there is at most one of each title. 
# You can accomplish this by creating a set, adding all the spells to it, 
# then iterating over the set and adding all the spells back into 
# a List and returning the list.

# It makes no sense to learn a spell twice! Once it's learned, it's learned forever.
