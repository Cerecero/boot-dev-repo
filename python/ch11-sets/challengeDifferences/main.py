def find_missing_ids(first_ids, second_ids):
    all_ids = []
    all_ids = set(first_ids)-set(second_ids)
    return list(all_ids)


    #list of all present id in the first list but not the second
    # 1stlist = [1,2,2,2,3] [1,2] === [3]
    #Remove duplicats
