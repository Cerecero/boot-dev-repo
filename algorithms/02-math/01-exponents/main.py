def get_estimated_spread(audiences_followers):
    if not audiences_followers:
        return 0

    sum = 0
    for follower in audiences_followers:
        sum += follower

    average_audience_followers = sum/len(audiences_followers)

    estimated_spread = average_audience_followers * (len(audiences_followers)**1.2)
    return estimated_spread
