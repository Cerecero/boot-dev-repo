class HashMap:
    def insert(self, key, value):
        index = self.key_to_index(key)
        original_index = index
        first_iteration = True
        while self.hashmap[index] is not None and self.hashmap[index][0] is not key:
            if not first_iteration and index == original_index:
                raise Exception("hashmap is full")
            index = (index + 1) % len(self.hashmap)
            first_iteration = False

        self.hashmap[index] = (key, value)

    def get(self, key):
        index = self.key_to_index(key)
        original_index = index
        while self.hashmap[index] is not None:
            if self.hashmap[index][0] == key:
                return self.hashmap[index][1]
            
            index = (index + 1) % len(self.hashmap)
            if index == original_index:
                break
        raise Exception("sorry, key not found")

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


def test(size, items):
    print(f"Creating Hashmap with size: {size}")
    hm = HashMap(size)
    for item in items:
        key = item[0]
        val = item[1]
        try:
            print(f"Inserting ({key}, {val})...")
            hm.insert(key, val)
        except Exception as e:
            print(e)
    if len(items) > 0:
        key = items[0][0]
        print(f"Getting: {key}")
        print(hm.get(key))
    print("-------------------------------------")
    print(f"Hashmap:\n{hm}")
    print("=====================================")


def main():
    test(
        5,
        [
            ("Billy Beane", "General Manager"),
            ("Peter Brand", "Assistant GM"),
            ("Art Howe", "Manager"),
            ("Ron Washington", "Coach"),
            ("David Justice", "Designated Hitter"),
        ],
    )
    test(
        4,
        [
            ("Billy Beane", "General Manager"),
            ("Peter Brand", "Assistant GM"),
            ("Art Howe", "Manager"),
            ("Scott Hatteberg", "First Baseman"),
            ("David Justice", "Designated Hitter"),
            ("Paul DePodesta", "Analyst"),
            ("Ron Washington", "Coach"),
            ("Chad Bradford", "Pitcher"),
        ],
    )


main()
