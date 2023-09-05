
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cctype>

bool is_isogram(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c){ return std::tolower(c); });
    std::unordered_map<char, int> unique_dict;
    for (char i_char : text) {
        if (std::isalpha(i_char)) {
            if (unique_dict.find(i_char) == unique_dict.end()) {
                unique_dict[i_char] = 1;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::string text;
    std::cout << "Введите текст: ";
    std::cin >> text;

    if (is_isogram(text)) {
        std::cout << "Введенный текст является изограммой" << std::endl;
    } else {
        std::cout << "Введенный текст не является изограммой" << std::endl;
    }

    return 0;
}