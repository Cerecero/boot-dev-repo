def count_nested_levels(nested_documents, target_document_id, level=1):
    for key, value in nested_documents.items():
        print(level)
        print(target_document_id)
        if key == target_document_id:
            return level
        elif isinstance(value, dict):
            nested_level = count_nested_levels(
                nested_documents[key], target_document_id, level + 1)
            if nested_level != -1:
                return nested_level
    return -1
