def find_longest_word(document, longest_word=""):
    # Base case: if the document is empty, return the longest_word found so far
    if not document:
        return longest_word
    
    # Split the document into a list of words
    words = document.split()
    
    # Base case: if there are no words left to check, return the longest_word found
    if not words:
        return longest_word
    
    # Get the first word in the list
    first_word = words[0]
    
    # Compare the first word with the longest_word found so far
    if len(first_word) > len(longest_word):
        longest_word = first_word
    
    # Recur for the rest of the document (after the first word)
    return find_longest_word(' '.join(words[1:]), longest_word)

