valid_formats = [
    "docx",
    "pdf",
    "txt",
    "pptx",
    "ppt",
    "md",
]

# Don't edit above this line


def pair_document_with_format(doc_names, doc_formats):
    name_and_format = list(zip(doc_names, doc_formats))
    # valid_list = list(filter(filter_docs, name_and_format))
    valid_list = list(filter(lambda filter_docs: filter_docs[-1] in valid_formats, name_and_format))
    return valid_list


# def filter_docs(format_list):
#     if format_list[-1] in valid_formats:
#         return True
