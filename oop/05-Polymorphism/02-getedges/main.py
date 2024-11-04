class Rectangle:
    def __init__(self, x1, y1, x2, y2):
        self.__x1 = x1
        self.__y1 = y1
        self.__x2 = x2
        self.__y2 = y2
    # Get the leftmost x-coordinate
    def get_left_x(self):
        return min(self.__x1, self.__x2)
    # Get the rightmost x-coordinate
    def get_right_x(self):
        return max(self.__x1, self.__x2)
    # Get the topmost y-coordinate
    def get_top_y(self):
        return max(self.__y1, self.__y2)
    # Get thhe bottommost y-coordinate
    def get_bottom_y(self):
        return min(self.__y1, self.__y2)

    # min Return the smallest item in an iterable or the smallest of two or more arguments.
    # max Return the largest item in an iterable or the smallest of two or more arguments.

    # don't touch below this line

    def __repr__(self):
        return f"Rectangle({self.__x1}, {self.__y1}, {self.__x2}, {self.__y2})"

