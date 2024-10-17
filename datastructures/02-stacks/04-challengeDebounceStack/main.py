from stack import Stack


class DebounceStack(Stack):
    def push(self, arrow):
        if self.peek() != arrow:
            super().push(arrow)
