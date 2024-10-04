def get_follower_prediction(follower_count, influencer_type, num_months):
    type_of_influencer = 0
    if influencer_type == "fitness":
        type_of_influencer = 4
    elif influencer_type == "cosmetic":
        type_of_influencer = 3
    else:
        type_of_influencer = 2

    expected_growth = follower_count * (type_of_influencer ** (num_months ))
    return expected_growth
