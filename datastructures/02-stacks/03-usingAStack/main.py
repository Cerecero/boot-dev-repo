from stack import Stack


def is_balanced(input_str):
    stack = Stack()

    for char in input_str:
        if char == '(':
            stack.push(char)
        elif char == ')':
            if stack.size() == 0:
                return False
            stack.pop()
    return stack.size() == 0
    # stack = Stack()
    # list_string = list(input_str)
    # 
    # l_parenthesis = 0
    # r_parenthesis = 0
    #
    # for i in range(len(list_string)):
    #     stack.push(list_string[i])
    #     if stack.peek() == '(':
    #         l_parenthesis += 1
    #     else:
    #         r_parenthesis += 1
    # if l_parenthesis != r_parenthesis:
    #     return False
    # else:
    #     return True
