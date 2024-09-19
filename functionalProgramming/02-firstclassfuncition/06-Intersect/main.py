def get_common_formats(formats1, formats2):
    supported_formats = set(formats1).intersection(set(formats2))
    return supported_formats

