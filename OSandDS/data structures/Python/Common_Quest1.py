# Обязательное задание. Напишите программу, которая проверяет, является ли введённая строка
# изограммой. Строка состоит из множества латинских букв в разном регистре, пробелов и знаков
# препинания. Причём в изограмме пробелы или знаки препинания могут повторяться.

def is_isogram(text: str) -> bool:
    lower_text = text.lower()
    unique_dict = dict()
    for i_char in lower_text:
        if i_char.isalpha():
            if i_char not in unique_dict:
                unique_dict[i_char] = 1
            else:
                return False
    return True


if is_isogram(input("Введите текст: ")):
    print("Введенный текст является изограммой")
else:
    print("Введенный текст не явялется изограммой")

