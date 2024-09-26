from functools import reduce


def lines_with_sequence(char):
    def with_char(length):
        sequence = char * length

        def with_length(doc):
            count = reduce(lambda count, line: count +
                           (1 if sequence in line else 0), doc.splitlines(), 0)
            return count
            # count = 0
            # for i in doc.split():
            # if sequence in i:
            # count += 1
            # return count
        return with_length
    return with_char
