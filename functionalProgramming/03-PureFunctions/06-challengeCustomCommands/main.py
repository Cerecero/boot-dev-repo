default_commands = {}
default_formats = ["txt", "md", "html"]
saved_documents = {}

# Don't edit above this line


def add_custom_command(commands, new_command, function):
    # commands[new_command] = function
    # return commands
    default_commands = commands.copy()
    default_commands[new_command] = function
    return default_commands


def add_format(formats, format):
    # formats.append(format)
    # return formats
    default_formats = formats[:]
    default_formats.append(format)
    # return formats + [format]
    return default_formats


def save_document(docs, file_name, doc):
    saved_documents = docs.copy()
    saved_documents[file_name] = doc
    return saved_documents


def add_line_break(line):
    return line + "\n\n"
