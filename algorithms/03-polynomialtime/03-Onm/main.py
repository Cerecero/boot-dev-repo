def get_avg_brand_followers(all_handles, brand_name):
    count = 0

    for handles in all_handles:
        for handle in handles:
            if brand_name in handle:
                count += 1

    average = count/len(all_handles)
    return average
