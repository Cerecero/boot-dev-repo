def remove_emphasis_from_word(word):
    return word.strip('*') #remove emphasis from a single word

def remove_emphasis_from_line(line):
    return ' '.join(map(remove_emphasis_from_word, line.split()))
    # From each word in a line, split it
    # and pass it to the remove emphasis from word, to remove emphaiss
    # and joined back together with a space in between

def remove_emphasis(doc_content):
    return '\n'.join(map(remove_emphasis_from_line, doc_content.split('\n')))
    # for each line in a document, split it at the end of line
    # pass it to the remove emphaiss from line
    # join it back together
