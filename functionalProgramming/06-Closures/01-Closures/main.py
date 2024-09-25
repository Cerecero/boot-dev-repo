def word_count_aggregator():
    count = 0

    def number_of_words(doc):
        nonlocal count
        # for i in doc.split():
        # count+=1
        count += len(doc.split())
        return count

    return number_of_words
