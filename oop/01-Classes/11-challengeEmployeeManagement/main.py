class Employee:
    company_name = "Age of Dragons, Inc."  # Class variables
    total_employees = 0

    def __init__(self, first_name, last_name, id, position, salary):
        self.first_name = first_name
        self.last_name = last_name
        self.id = id
        self.salary = salary
        Employee.total_employees += 1 #Increments the class variable each time an object is created

    def get_name(self):
        return f"{self.first_name} {self.last_name}"
