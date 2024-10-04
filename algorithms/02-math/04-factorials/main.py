def num_possible_orders(num_posts):
    if num_posts == 0:
        return 1

    posts = num_posts
    orders = 1
    while posts > 0:
        orders *= posts
        posts -= 1
    return orders
