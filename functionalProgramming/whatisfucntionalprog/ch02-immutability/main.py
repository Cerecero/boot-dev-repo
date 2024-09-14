def add_prefix(document, documents):
    prefix = f"{len(documents)}. "
    new_doc = (prefix + document,)
    prefix_document = documents + new_doc
    return prefix_document
