class Stack:
    def __init__(self):
        self.items = []

    def push(self, arrow):
        self.items.append(arrow)
    def size(self):
        return len(self.items)
