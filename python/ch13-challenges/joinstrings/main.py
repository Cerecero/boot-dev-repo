def join_strings(strings):
    #CHATGPT ANSWER
    if not strings:
        return ""
    phrase = strings[0]

    for i in range(1, len(strings)):
        phrase += "," + strings[i]

    return phrase

    #MY ANSWER
    # for string in strings:
    #     if string == strings[-1]:
    #         phrase += string
    #     else:
    #         phrase += string + ","
    # return phrase
