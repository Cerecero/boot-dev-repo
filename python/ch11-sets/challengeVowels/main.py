def count_vowels(text):
    set_vowels = set()
    count = 0
    for t in text:
        if t == "a" or t == "e" or t == "i" or t == "o" or t == "u" or t== "A" or t== "E" or t== "I" or t== "O" or t == "U":
            count += 1
            set_vowels.add(t)
    return count, set_vowels

# text = "Did someone say Thunderfury, Blessed Blade of the Windseeker?"

# count_vowels(text)
