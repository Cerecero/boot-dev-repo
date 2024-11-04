class HashMap:
    def insert(self, key, value):
        # Use the key_to_index method to get the index
        index = self.key_to_index(key)
        # Store the key-value pair as a tuple
        self.hashmap[index] = (key, value)

    # don't touch below this line

    def __init__(self, size):
        self.hashmap = [None for i in range(size)]

    def key_to_index(self, key):
        sum = 0
        for c in key:
            sum += ord(c)
        return sum % len(self.hashmap)

    def __repr__(self):
        final = ""
        for i, v in enumerate(self.hashmap):
            if v != None:
                final += f" - {i}: {str(v)}\n"
            else:
                final += f" - {i}: None\n"
        return final
