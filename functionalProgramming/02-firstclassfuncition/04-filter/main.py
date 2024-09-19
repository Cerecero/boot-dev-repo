def remove_invalid_lines(document):
    return "\n".join(list(filter(lambda line: line.startswith("*"), document.split("\n"))))

    # split_doc = document.split("\n")
    # print(split_doc)
