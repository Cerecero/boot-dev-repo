def filter_messages(messages):
    filter_words = []
    dang_count = []
    for message in messages:
        message_list = message.split()
        non_bad_word = []
        counter = 0
        for word in message_list:
            if word == 'dang':
                counter += 1
            else:
                non_bad_word.append(word)
            sentence = " ".join(non_bad_word)
        filter_words.append(sentence)
        dang_count.append(counter)
    return filter_words, dang_count
