
def jusifyText(words, k):
    # text = ' '.join(words)
    # print(text)
    last_word = words.pop()
    line = ""
    words_lines = []
    words_to_use = []

    while words:
        word = words.pop(0)
        if len(line)+len(word)+1<=k:
            words_to_use.append(word)
            line = line+word+" "
        else:
            words_lines.append(words_to_use)
            words_to_use = [word]
            line = word+" "

    if len(line)+len(last_word)<=k:
        words_to_use.append(last_word)
        line = line+last_word
    else:
        words_lines.append(words_to_use)
        words_to_use = [word]
        line = word

    words_lines.append(words_to_use)
    # print(words_lines)
    actual_lines = []
    for words_line in words_lines:
        num_words = len(words_line)
        num_space_places = num_words-1
        word_space = sum(len(word) for word in words_line)
        blank_space = k-word_space
        spaces = [0 for _ in range(num_space_places)]

        i = 0
        while blank_space>0:
            spaces[i]+=1
            if i==num_space_places-1:
                i=0
            else:
                i+=1
            blank_space-=1
        # print(spaces)

        real_spaces = [" "*space for space in spaces]
        actual_line = ""
        while real_spaces:
            actual_line += words_line.pop(0)
            actual_line += real_spaces.pop(0)
        actual_line+=words_line.pop(0)
        actual_lines.append(actual_line)
    return actual_lines


if __name__=='__main__':
    words = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
    k = 16
    text = jusifyText(words, k)
    for line in text:
        print(line)
