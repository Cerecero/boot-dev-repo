class Trie:
    def search_level(self, cur, cur_prefix, words):
        if self.end_symbol in cur:
            words.append(cur_prefix)

        for key in sorted(cur.keys()):
            if key is not self.end_symbol:
                self.search_level(cur[key], cur_prefix + key, words)
        return words

    def words_with_prefix(self, prefix):
        hold_words = []
        current = self.root
        for char in prefix:
            if char not in current:
                return []
            current = current[char]
        return self.search_level(current, prefix, hold_words)

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
