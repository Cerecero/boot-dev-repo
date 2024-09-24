def zipmap(keys, values):
    if not keys or not values:
        return {}
    dictionary = {keys[0]: values[0]}
    dictionary.update(zipmap(keys[1:], values[1:]))
    return dictionary
