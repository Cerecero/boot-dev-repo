def main():
    frankenseintBook = "books/frankenstein.txt"
    with open(frankenseintBook) as f:
        file_contents = f.read()

        character_count = check_freq(file_contents.lower())
        list = dict_to_list(character_count)
        word_count = len(file_contents.split())
        print("The number of words is: " , word_count)
        for char in list:
           print(f"The '{char['char']}' chcarecter was found {char['num']} times")

        print("--- End of the report ---")
def sort_on(dict):
    return dict["num"]

def dict_to_list(dict):
    list = []
    for i in dict:
        list.append({"char": i, 
                    "num": dict[i]})

    list.sort(reverse=True, key=sort_on)
    return list

def check_freq(x): 
    freq={}
    for c in set(x):
        freq[c] = x.count(c)
    return freq


main()

