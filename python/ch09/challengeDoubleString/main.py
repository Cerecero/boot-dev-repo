def double_string(string):
    doubled = ""
    for char in string:
        doubled += char * 2
    return doubled
    # sentence = []
    # for s in string.split():
    #     for i in s:
    #         sentence.append(i)
    #         sentence.append(i)
    #     sentence.append(" ")
    #
    # sentence = "".join(sentence)
    # print(sentence)
    # return sentence
# run = 'Hello There'

# double_string(run)


# Double the string!
# The fantasy quest team wants to add a new easter egg potion to Fantasy Quest! 
# It causes characters to have their in-game chat manipulated when they send messages. 
# The potion doubles every character they send!
#
# The message they type: Hello there
# The message that is sent: HHeelllloo  tthheerree
# Assignment
# Complete the double_string function. It takes a string as input and returns a "doubled" version, including spaces!
#
# Example output
#
# sentence = "LF3M BRD full clear"
# print(double_string(sentence)) # "LLFF33MM  BBRRDD  ffuull  cclleeaarr"
# Copy icon
# Tip
# You can iterate over a string as if it were a list of individual characters.
#
# string = "hello world"
# for character in string:
#     # process individual characters here
