from node import Node


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def add_to_head(self, node):
        if self.head is None:
            self.tail = node
            self.head = node
        else:
            node.set_next(self.head)
            self.head = node

    def add_to_tail(self, node):
        if self.head is None:
            self.head = node
            self.tail = node
        else:
            self.tail.set_next(node)
            self.tail = node

    # don't touch below this line

    def __iter__(self):
        node = self.head
        while node is not None:
            yield node
            node = node.next

    def __repr__(self):
        nodes = []
        for node in self:
            nodes.append(node.val)
        return " -> ".join(nodes)
