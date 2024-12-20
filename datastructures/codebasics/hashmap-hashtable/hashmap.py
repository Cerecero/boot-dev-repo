class HashTable:
    def __init__(self):
        self.MAX = 100
        self.arr = [None for i in range(self.MAX)]
    
    def get_hash(self, key):
        h = sum(ord(char) for char in key)
        return h % 100 #100 is the assumed size  of the array

    def __setitem__(self, key, val):
        h = self.get_hash(key)
        self.arr[h] = val

    def __getitem__(self, key):
        h = self.get_hash(key)
        return self.arr[h]
    def __delitem__(self, key):
        h = self.get_hash(key)
        self.arr[h] = None
t = HashTable()
t['march 6'] = 136
t['march 1'] = 20
t['march 2'] = 30
t['march 5'] = 60
del t['march 1']
print(t.arr)

