class Trie:
    def find_matches(self, document):
        occur = set()
        
        for i in range(len(document)):
            level = self.root
            for j in range(i, len(document)):
                char = document[j]
                if char not in level:
                    break
                level = level[char]
                if self.end_symbol in level:
                    word = document[i:j+1]
                    occur.add(word)


        return occur

    # don't touch below this line

    def __init__(self):
        self.root = {}
        self.end_symbol = "*"

    def add(self, word):
        current = self.root
        for letter in word:
            if letter not in current:
                current[letter] = {}
            current = current[letter]
        current[self.end_symbol] = True
