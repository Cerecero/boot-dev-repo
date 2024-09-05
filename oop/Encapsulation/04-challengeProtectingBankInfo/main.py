class BankAccount:
    def __init__(self, account_number, initial_balance):
        self.__account_number = account_number  # Initialize private instance variables
        self.__balance = initial_balance

    def get_account_number(self):
        return self.__account_number  # getter method for account number

    def get_balance(self):
        return self.__balance  # getter method for balance

    def deposit(self, amount):
        if amount <= 0:  # if amount isnt positive, raise ValueError
            raise ValueError("Cannot deposit zero or negative funds")
        else:  # adds amount to __balance
            self.__balance += amount

    def withdraw(self, amount):
        if amount <= 0:  # if amount isnt positive raise Value Error
            raise ValueError("Cannot withdraw zero or negative funds")
        elif amount > self.__balance:  # If amount is bigger than the balance, raise Value error
            raise ValueError("Insufficient funds")
        else:  # reduce amount from balance
            self.__balance -= amount
