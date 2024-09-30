def user_words(initial_words):
    
    word_tuple = initial_words
    def add_word(word):
        nonlocal word_tuple
        word_tuple += (word,)
        return word_tuple
    return add_word
