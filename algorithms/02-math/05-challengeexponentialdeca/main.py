def decayed_followers(intl_followers, fraction_lost_daily, days):
    # if intl_followers == 0 :
        # return 0
    # elif fraction_lost_daily == 0:
        # return intl_followers

    retention_rate = 1 -fraction_lost_daily

    remaining_followers = intl_followers * (retention_rate ** days)
    return remaining_followers
