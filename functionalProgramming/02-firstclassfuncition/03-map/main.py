def change_bullet_style(document):
    return "\n".join(list(map(convert_line, document.split('\n'))))

    # The code below and above works, and its separated in variables for better reading
    # lines_list = document.split('\n')
    # changed = list(map(convert_line, lines_list))
    # rejoined_document = "\n".join(changed)
    # return rejoined_document


# Don't edit below this line


def convert_line(line):
    old_bullet = "-"
    new_bullet = "*"
    if len(line) > 0 and line[0] == old_bullet:
        return new_bullet + line[1:]
    return line
