def validate_path(expected_path, character_path):
    character_name = character_path.pop(0)
    percentage = 0.0
    for i in range(len(expected_path)):
        if expected_path[i] == character_path[i]:
            percentage += 1
    percentage = (percentage/len(expected_path)*100)
    return character_name, percentage


expected = ["A", "B", "C", "D", "E"]
character = ["Kaladin", "A", "X", "C", "D", "E"]

validate_path(expected, character)
# Validate Path
# The Fantasy Quest is implementing a new type of quest that requires
# a player to follow a specific path in order to complete the quest.
#
# Assignment
# Complete the validate_path function.
# It should compare the expected sequence of waypoints with the actual sequence taken
# by a character and calculate how accurately the character followed the intended path.
#
# Inputs
# expected_path: A list of waypoints that define the correct path for the quest.
# character_path: A list where the first index is the name of the character,
# and the rest of the list consists of the waypoints they actually visited.

# Output
# The function should return 2 values:
#
# character_name: a string
# percentage: a float

# Example
# expected_path = ["A", "B", "C", "D"]
# character_path = ["Hero123", "A", "X", "C", "D"]
# name, percent = validate_path(expected_path, character_path)
# print(name, percent)
# # prints: Hero123, 75.0
