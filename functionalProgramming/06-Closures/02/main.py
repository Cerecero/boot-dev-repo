def new_collection(initial_docs):
    doc = initial_docs.copy()
    def updated_docs(new_document):
        doc.append(new_document)
        return doc
        
    return updated_docs
