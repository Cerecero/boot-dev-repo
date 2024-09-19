import functools


def join(doc_so_far, sentence):
    return doc_so_far + ". " + sentence


def join_first_sentences(sentences, n):
    return functools.reduce(join, sentences[:n])
