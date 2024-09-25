keywords = [
    "functional",
    "immutable",
    "declarative",
    "higher-order",
    "lambda",
    "deterministic",
    "side-effects",
    "memoization",
    "referential transparency",
]


def index_keywords(document, index):
    copy_index = index.copy()
    if document in copy_index:
        return copy_index[document], copy_index
    found_keywords = find_keywords(document)
    copy_index[document] = found_keywords
    return found_keywords, copy_index


def find_keywords(document):
    document_words = document.split()
    found_keywords = []
    for keyword in keywords:
        if keyword in document_words:
            found_keywords.append(keyword)
    return found_keywords
