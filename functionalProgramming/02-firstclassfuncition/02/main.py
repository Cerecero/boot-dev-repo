def file_type_getter(file_extension_tuples):
    file_dict = {}
    for file, extension in file_extension_tuples:
        for e in extension:
            file_dict[e] = file
    print(file_dict)
    return lambda extension: file_dict.get(extension, "Unknown")
