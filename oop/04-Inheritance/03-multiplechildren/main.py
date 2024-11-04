class Hero:
    def __init__(self, name, health):
        self.__name = name
        self.__health = health

    def get_name(self):
        return self.__name

    def get_health(self):
        return self.__health

    def take_damage(self, damage):
        self.__health -= damage


class Archer(Hero):
    def __init__(self, name, health, num_arrows):
        # Call to the Hero constructor to set up name and health
        super().__init__(name, health)

        # Setting a private variable for number of arrows
        self.__num_arrows = num_arrows

    def shoot(self, target):
        # Check if Archer has arrows left
        if self.__num_arrows<= 0:
            raise Exception("not enough arrows")
        else:
        # This else could be deleted
        # Use an arrow
            self.__num_arrows -= 1
        #Deal 10 damage tot he target hero
            target.take_damage(10)
