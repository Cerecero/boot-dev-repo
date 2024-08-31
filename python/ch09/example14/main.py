def get_first_item(items):
    for item in items:
        if not items:
            return "ERROR"
        else:
            return items[0]
