fireball_damage = 500
potion_mana = 100
fireball_cost = 50


class Wizard:
    def __init__(self, name, stamina, intelligence):
        self.name = name
        self.__stamina = stamina
        self.__intelligence = intelligence
        self.mana = self.__intelligence * 10
        self.health = self.__stamina * 100

    def cast_fireball(self, target):
        if self.mana < fireball_cost: #if the mana is less than the cost of fireball
            raise Exception(f"{self.name} cannot cast fireball") #raise this exception
        else:
            self.mana = self.mana - fireball_cost  #else reduce mana by the cost of fireball_cost
            target.get_fireballed() #and call get_fireballed on the target so that it takes damage

    def __is_alive(self):
        if self.health > 0: #if health is not 0
            return True #return true if not false
        else:
            return False

    def get_fireballed(self):
        self.health -= fireball_damage

    def drink_mana_potion(self):
        self.mana += potion_mana


# don't touch below this line


def main():
    merlin = Wizard("Merlin", 15, 10)
    morgana = Wizard("Morgana", 17, 5)
    print_wizard_stats(merlin)
    print_wizard_stats(morgana)

    while merlin._Wizard__is_alive() and morgana._Wizard__is_alive():
        test_cast(merlin, morgana)
        test_cast(morgana, merlin)

    print(" -- Done! --")


def test_cast(caster, target):
    print(f"  >  {caster.name} casts fireball at {target.name}")
    try:
        caster.cast_fireball(target)
    except Exception as e:
        print(f"    >  !!!{e}!!!")
        test_drink_potion(caster)
    print_wizard_stats(caster)
    print_wizard_stats(target)


def test_drink_potion(caster):
    print(f"  >  {caster.name} drinks mana potion")
    caster.drink_mana_potion()


def print_wizard_stats(wizard):
    print(f"{wizard.name}: health={wizard.health}, mana={wizard.mana}")


main()
