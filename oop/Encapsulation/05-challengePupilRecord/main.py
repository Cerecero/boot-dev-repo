class Student:
    def __init__(self, name):
        self.name = name # instance variable name equals name parameter
        self.__courses = {} #empty dictionary

    def calculate_letter_grade(self, score):
        if score >= 90: #if score is above 90 return A
            return "A"
        elif score >= 80 and score < 90: # if score is above 80 and less than 89 return B
            return "B"
        elif score >= 70 and score < 80: # if score is above 70 and less than 79 return C
            return "C"
        elif score >= 60 and score < 70: # if score is above 60 and less than 69 return D
            return "D"
        else: #else return F
            return "F"
    def add_course(self, course_name, score): 
        self.__courses[course_name] = Student.calculate_letter_grade(self, score)
        #Add to diciontary __courses the key [course_name] and the value calculated_letter_grade
    def get_courses(self):
        return self.__courses #returns the dictionary

