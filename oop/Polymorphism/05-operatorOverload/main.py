class Sword:
    def __init__(self, sword_type):
        self.sword_type = sword_type

    def __add__(self, other):
        # If this object sword type is equal to other.sword_type and its equal to bronze, return sword object with iron
        if self.sword_type == other.sword_type == "bronze":
            return Sword("iron")
        # If this object sword type is equal to other.sword_type and its equal to iron, return sword object with steel
        elif self.sword_type == other.sword_type == "iron":
            return Sword("steel")
        else:
            raise Exception("can not craft")

