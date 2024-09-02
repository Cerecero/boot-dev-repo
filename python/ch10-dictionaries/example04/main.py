def get_most_common_enemy(enemies_dict): #This solution after checking it with an AI, to spot mistakes
    if not enemies_dict: #Before anything else check if the dictionary is empty
        return None
    max_so_far = float("-inf")
    enemy_name = None

    for num in enemies_dict:
        if enemies_dict[num] > max_so_far:
            max_so_far = enemies_dict[num]
            enemy_name = num #num is the key#
    return enemy_name
# my solution
#for num in enemies_dict:
        #if enemies_dict[num] > max_so_far:
            #max_so_far = enemies_dict[num]
            #enemy_name = num #num is the key#
        #elif enemies_dict[num] == None:
            #return None
