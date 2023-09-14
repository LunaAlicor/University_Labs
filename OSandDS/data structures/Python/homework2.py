# how are you ? = Sure
# FASFAFFS = Whoa, chill out!
# SFAFSAS? = Calm down, i know what iam doing!
#   = Fine.Be that way!
# остальные случаи = Whatever


def find_answer(massage):
    answers = {
        0: 'Sure',
        1: 'Whoa, chill out!',
        2: 'Calm down, i know what iam doing!',
        3: 'Fine.Be that way!',
        4: 'Whatever'
    }
    lower_flag = 0
    question_flag = 0
    if massage.isspace() or massage == '':
        return answers[3]
    else:
        for i_char in massage:
            if i_char.isalpha() and i_char == i_char.lower():
                lower_flag = 1
            elif i_char == '?':
                question_flag = 1
    if lower_flag == 1 and question_flag == 0:
        return answers[4]
    elif lower_flag == 1 and question_flag == 1:
        return answers[0]
    elif lower_flag == 0 and question_flag == 0:
        return answers[1]
    elif lower_flag == 0 and question_flag == 1:
        return answers[2]


while True:
    text = input("Введите ваше сообщение: ")
    if text.lower() == 'goodbay':
        print('Goodbay!')
        break
    else:
        print(find_answer(text))
