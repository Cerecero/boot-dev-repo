class HashMap:
    def insert(self, key, value):
        self.resize()

        index = self.key_to_index(key)
        self.hashmap[index] = (key, value)

    def resize(self):
        if len(self.hashmap) == 0:
            self.hashmap = [None]

        load_factor = self.current_load()
        if load_factor < 0.05:
            return
        new_size = len(self.hashmap) * 10
        new_hashmap = [None for _ in range(new_size)]

        old_hashmap = self.hashmap
        self.hashmap = new_hashmap

        for item in old_hashmap:
            if item is not None:
                key, value = item
                self.insert(key, value)


    def current_load(self):
        if len(self.hashmap) == 0:
            return 1
        filled = 0
        for bucket in self.hashmap:
            if bucket is not None:
                filled += 1
        return filled / len(self.hashmap)

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
                final += f" - {str(v)}\n"
        return final
