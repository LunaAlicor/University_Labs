# Вариант 8
# Описание: Напишите программу, которая подсчитает количество подстрок с уникльными символами во введенной строке
# Подстрока считается уникальной если все символы в ней различны
# пример
# ввод "abac"
# Вывод: Количество подстрок с уникальными символами: 5
# Пояснени: Подстроки с уникальными символами: "a", "b", "c", "ab", "ac"


def unique_symbol_check(txt:str) -> bool:
    unique_symbol_dict = dict()
    for i_char in txt:
        if i_char not in unique_symbol_dict:
            unique_symbol_dict[i_char] = 1
        else:
            return False
    return True


def substring_search(txt: str, length: int) -> int:
    unique_dict = dict()
    for i in range(len(txt)-length+1):
        substring = txt[i:i+length]
        if substring and reversed(substring) not in unique_dict:
            if unique_symbol_check(substring):
                unique_dict[substring] = 1
        else:
            pass
    print(unique_dict)
    return len(unique_dict)


def substring_count(txt: str) -> int:
    # unique_substrings = dict()
    unique_substrings_count = 0
    min_len = 1
    while min_len < len(txt):
        unique_substrings_count += substring_search(txt=txt, length=min_len)
        min_len += 1
    return unique_substrings_count


print(substring_count(input("Введите строку: ")))
