class Stack:
    def __init__(self):
        self.items = []

    def push(self, arrow):
        self.items.append(arrow)

    def size(self):
        return len(self.items)

    def pop(self):
        if not self.items:
            return None
        return self.items.pop()

    def peek(self):
        if not self.items:
            return None
        return self.items[-1]
