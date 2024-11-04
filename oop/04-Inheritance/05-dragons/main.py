class Unit:
    def __init__(self, name, pos_x, pos_y):
        self.name = name
        self.pos_x = pos_x
        self.pos_y = pos_y

    def in_area(self, x_1, y_1, x_2, y_2):
        # Check if the unit position is withing or on the rectangle boundary
        if self.pos_x >= x_1 and self.pos_x <= y_2 and self.pos_y >= y_1 and self.pos_y <= x_2:
            return True
        else:
            return False
        # This code uses chained comparison:
            # return x_1 <= self.pos_x <= x_2 and y_1 <= self.pos_y <= y_2


class Dragon(Unit):
    def __init__(self, name, pos_x, pos_y, fire_range):
        super().__init__(name, pos_x, pos_y)
        self.__fire_range = fire_range

    def breathe_fire(self, x, y, units):
        # Define the area affected by the dragons fire
        x_1 = x - self.__fire_range
        y_1 = y - self.__fire_range
        x_2 = x + self.__fire_range
        y_2 = y + self.__fire_range
        # Empty list to store the units that where hit by the dragon
        unit_list = []
        # Loop to see if a unit is in the blast area
        for unit in units:
            if unit.in_area(x_1, y_1, x_2, y_2):
                unit_list.append(unit)
        return unit_list
