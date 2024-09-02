def merge(dict1, dict2):
    # ChatGPT solution for this problem
    # merged_dict = dict1.copy()
    # merged_dict.update(dict2)
    # return merged_dict
    

    #My Solution for this challenge
    for dic in dict1:
        if dic in dict2:
            dict1[dic] = dict2[dic]
    dict1.update(dict2)
    return dict1


def total_score(score_dict):
    # ChatGPT solution for this problem
    # return sum(score_dict.values())
    

    #My Solution for this challenge
    score = 0
    for key in score_dict:
        score += score_dict[key]
    return score
 # dic1 = {"first_quarter": 24, "second_quarter": 31}
 # dic2 ={"second_quarter": 3, "third_quarter": 31, "fourth_quarter": 0}
 # merge(dic1, dic2)
