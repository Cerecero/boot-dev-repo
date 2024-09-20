def add_format(default_formats, new_format):
    copy_formats = default_formats.copy()
    copy_formats[new_format] = True
    return copy_formats


def remove_format(default_formats, old_format):
    copy_formats = default_formats.copy()
    copy_formats[old_format] = False
    return copy_formats
