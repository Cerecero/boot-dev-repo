def restore_documents(originals, backups):
    return set(filter(lambda digit: not digit.isdigit(), map(str.upper, originals + backups)))
