def markdown_to_text_decorator(func):
    def wrapper(*args, **kwargs):
        # Convert each positional argument using convert_md_to_txt
        new_args = [convert_md_to_txt(arg) if isinstance(
            arg, str) else arg for arg in args]

        # Convert each keyword argument's value using convert_md_to_txt
        new_kwargs = {key: convert_md_to_txt(value) if isinstance(
            value, str) else value for key, value in kwargs.items()}

        # Call the original function with the modified arguments and return the result
        return func(*new_args, **new_kwargs)

    return wrapper

# don't touch below this line


def convert_md_to_txt(doc):
    lines = doc.split("\n")
    for i in range(len(lines)):
        line = lines[i]
        lines[i] = line.lstrip("# ")
    return "\n".join(lines)
