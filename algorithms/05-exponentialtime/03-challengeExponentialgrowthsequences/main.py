def exponential_growth(n, factor, days):
    # Use a geometric sequence formula that's slightly modified for this problem: total = a1 * r^n
    # expected_growth = follower_count * (type_of_influencer ** (num_months ))

    # For example, if a fitness influencer starts with 10 followers, then after 1 month they should have 40 followers. After 2 months, they would have 160 followers; etc.gcc
    
    # expected_followers = n * (factor ** days)
    expected_followers = []
    for day in range(days+1):
        expected_followers.append(n)
        n *= factor
        # expected_followers.append(n * (factor ** day))

    return expected_followers

