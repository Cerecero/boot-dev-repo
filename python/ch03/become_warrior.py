def become_warrior(first_name, last_name, power):
    title = f"{first_name} {last_name} the warrior"  # format the person's title
    new_power = power# replace with the correct value
    return title, new_power


# Don't edit below this line


def main():
    test("Frodo", "Baggins", 5)
    test("Bilbo", "Baggins", 10)
    test("Gandalf", "The Grey", 9000)


def test(first_name, last_name, power):
    title, new_power = become_warrior(first_name, last_name, power)
    print(title, "has a power level of:", new_power)


main()
