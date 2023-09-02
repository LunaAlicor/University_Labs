#include<iostream>
#include<string>
#include <unordered_map>
#include <algorithm>

using namespace std;

void print_unordered_map(unordered_map<string, int> map) {
    for (auto &pair : map) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

bool unique_symbol_check(string txt){
    unordered_map<char, int> unique_symbol_map;
    for (char i_char : txt){
        if (unique_symbol_map.find(i_char) == unique_symbol_map.end()){
            unique_symbol_map[i_char] = 1;
        } else {
            return false;
        }
    }
    return true;
}


int substring_search(string txt, int length){
    unordered_map<string, int> unique_unordered_map;
    for (int i = 0; i <= txt.length()-length; i++) {
        string substring = txt.substr(i, length);
        string reversed_substring = substring;
        reverse(reversed_substring.begin(), reversed_substring.end());

        if (!substring.empty() && unique_unordered_map.find(substring) == unique_unordered_map.end()) {
            if (unique_symbol_check(substring)) { 
                unique_unordered_map[substring] = 1;
            }
        }
    }
    print_unordered_map(unique_unordered_map);
    return unique_unordered_map.size();
}


int substring_count(string txt){
    int unique_substrings_count, min_len;
    unique_substrings_count = 0;
    min_len = 1;
    while (min_len < txt.length()){
        unique_substrings_count += substring_search(txt, min_len);
        min_len += 1;
    }
    return unique_substrings_count; 
}


int main() {

    string text;
    cout << "Введите строку: ";
    cin >> text;
    int count = substring_count(text);
    cout << count << " уникальные подстроки";
    return 0;
}