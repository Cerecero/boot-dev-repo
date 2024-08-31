def calculate_total(items_purchased, pinned_list):
    item_prices = {
        "health_potion": 10.00,
        "mana_potion": 12.00,
        "gold_dust": 5.00,
        "dwarven_ale": 8.00,
        "enchanted_scroll": 25.00,
        "ice_cold_milk": 50.00,
        "herbs": 7.00,
        "crystal_shard": 20.00,
        "magic_ring": 100.00,
        "mystic_amulet": 150.00,
    }

    # Don't touch above this line

    unpurchased_items = []
    receipt = {}
    total = 0
    
    for item in pinned_list:

        if item not in items_purchased:
            unpurchased_items.append(item)
    for item in items_purchased:
        # if item not in pinned_list:gcc
            # unpurchased_items.append(item)

        receipt[item] = item_prices[item]

        total += item_prices[item]

    return unpurchased_items, receipt, total

#ChatGPT Fixing my solution
# # Find unpurchased items

#   for item in pinned_list:
#       if item not in items_purchased:
#         unpurchased_items.append(item)
# 
# # Create receipt and calculate total

# for item in items_purchased:
#     if item in item_prices:  # This check prevents KeyError
#         receipt[item] = item_prices[item]
#         total += item_prices[item]
#
# return unpurchased_items, receipt, totalV
#-----------------------------------------------#
    #Solution to the assignment by CHATGPY
    # 1. Identify Unpurchased Items
    # unpurchased_items = [item for item in pinned_list if item not in items_purchased]
    # 
    # # 2. Create the Receipt
    # receipt = {}
    # for item in items_purchased:
    #     if item in item_prices:  # Check if item is in item_prices to avoid KeyError
    #         receipt[item] = item_prices[item]
    # 
    # # 3. Calculate the Total Cost
    # total = sum(receipt.values())
    # 
    # return unpurchased_items, receipt, total
