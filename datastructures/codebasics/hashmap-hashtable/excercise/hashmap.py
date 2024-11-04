import csv


class HashTable:
    def __init__(self):
        self.MAX = 100
        self.arr = [[] for i in range(self.MAX)]

    def get_hash(self, key):
        h = sum(ord(char) for char in key)
        return h % 100  # 100 is the assumed size  of the array

    def __setitem__(self, key, val):
        h = self.get_hash(key)
        found = False
        for idx, element in enumerate(self.arr[h]):
            if len(element)==2 and element[0]==key:
                self.arr[h][idx] = (key,val)
                found = True
                break
        if not found:
            self.arr[h].append((key, val))

    def __getitem__(self, key):
        h = self.get_hash(key)
        for element in self.arr[h]:
            if element[0] == key:
                return element[1]

    def __delitem__(self, key, val):
        h = self.get_hash(key)
        for index, element in enumerate(self.arr[h]):
            if element[0] == key:
                del self.arr[h][index]
t = HashTable()

with open('nyc_weather.csv', newline='') as csvfile:

    linereader = csv.reader(csvfile, delimiter=',', quotechar='|')
    line = 0
    for row in linereader:
        if line == 0:
            line += 1
            pass
        else:
            t[row[0]] = row[1]
average = 0
count = 0
# for index, element in enumerate(t.arr):
#     if element:
#         count += 1
#         average += int(element[0][1])
for index, element in enumerate(t.arr):
    if element:
        if element[0][0] == 'Jan 4':
            print(element[0][1])

# t = HashTable()
# t['march 6'] = 136
# t['march 1'] = 20
# t['march 2'] = 30
# t['march 5'] = 60
# del t['march 1']
# print(t.arr)

