def word_count_memo(document, memos):
    copy_memos = memos.copy() #Creates a copy of the dictionary
    if document in memos: # if the given document string is in memos dict
        return memos[document], copy_memos # Return the word count and the copy dictionary
    else:
        copy_memos[document] = word_count(document) # else create a key of the current document, and use the function word_count to get the number of words, and return that as a value
        return copy_memos[document], copy_memos # Return the word count and the copy dictionary


# Don't edit below this line


def word_count(document):
    count = len(document.split())
    return count

