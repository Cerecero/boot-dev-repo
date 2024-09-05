class Book:
    def __init__(self, title, author):
        self.title = title  # setting values of that of the parameters
        self.author = author  # setting values that of the parameters


class Library:
    def __init__(self, name):
        self.name = name  # setting name to the parameter name
        self.books = []  # initialized an empty list

    def add_book(self, book):
        # book = Bookr()
        # appending book which is an instance of the Class Book,
        self.books.append(book)
        # This line of code appends book to the list self.books
        # book is an object like this: Book("The Trial", "Franz Kafka")

    def remove_book(self, book):
        for b in self.books:  # loops thorugh self.book list
            print(f"This is b.title: {b.title}")
            # If b (which is a Book object from the self.books list)
            if b.title == book.title and b.author == book.author:
                # and this if is comparing it to the title and author of the book object passed as a parameter
                # This removes the Book object b from the list self.book
                self.books.remove(b)
                break  # to exit the loop

    def search_books(self, search_string):
        search_string = search_string.lower()  # lowersCase the paratmeter search_string

        match_books = []  # creates an empty list

        for book in self.books:  # loops through the self.books list
            if search_string in book.title.lower() or search_string in book.author.lower():
                # if search string is inside the book.title or book.author in lower case
                # adds the matching result to the list match_books
                match_books.append(book)

        return match_books  # return match_books
