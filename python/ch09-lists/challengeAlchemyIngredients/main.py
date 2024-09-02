def check_ingredient_match(recipe, ingredients):
    percentage = 0.0
    missing =[]
    for i in range(0, len(recipe)):
        if recipe[i] == ingredients[i]:
            percentage += 1
        else:
            missing.append(recipe[i])
    percentage = (percentage/len(recipe)*100)
    return percentage, missing

    # percentage = (percentage/len(expected_path)*100)
# recipe = [
#     "Dragon Scale",
#     "Unicorn Hair",
#     "Phoenix Feather",
#     "Troll Tusk",
#     "Mandrake Root",
#     "Griffin Feather",
#     "Elf Dust",
#     "Goblin Ear",
# ]
# ingredients = [
#     "Dragon Scale",
#     "Goblin Ear",
#     "Phoenix Feather",
#     "Elf Dust",
#     "Mandrake Root",
#     "Griffin Feather",
#     "Elf Dust",
#     "Goblin Ear",
# ]
# check_ingredient_match(recipe, ingredients)

#
# Alchemy Ingredients
# Fantasy Quest added a new alchemy profession, users would like a way to know how many ingredients they have compared to the required ingredients in their recipes.
#
# Assignment
# Finish the check_ingredient_match function by looping over the recipe list. The function should calculate and return a percentage of ingredients the character has. As well as a list of missing ingredients from the recipe.
#
# The placement of the ingredients matter! They must be in the same index as the recipe!
#
# For example, if these were the lists:
#
# recipe = ["Dragon Scale", "Unicorn Hair", "Phoenix Feather", "Troll Tusk"]
# ingredients = ["Dragon Scale", "Goblin Ear", "Phoenix Feather", "Troll Tusk"]
#
# percentage, ingredients = check_ingredient_match(recipe, ingredients)
# print(percentage, ingredients)
# # Prints: 75.00 ["Unicorn Hair"]
# Copy icon
# The percentage must be a float, not an integer!
