class Rectangle:
    def overlaps(self, rect):
        if (self.get_left_x() <= rect.get_right_x() and
            self.get_right_x() >= rect.get_left_x() and
            self.get_top_y() >= rect.get_bottom_y() and
            self.get_bottom_y() <= rect.get_top_y()):
            return True
        else:
            return False
        # This code also works and is less lines
        # return (
        #     self.get_left_x() <= rect.get_right_x()
        #     and self.get_right_x() >= rect.get_left_x()
        #     and self.get_top_y() >= rect.get_bottom_y()
        #     and self.get_bottom_y() <= rect.get_top_y()
        # )

    # don't touch below this line

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

    def __repr__(self):
        return f"Rectangle({self.__x1}, {self.__y1}, {self.__x2}, {self.__y2})"
