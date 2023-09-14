#include <iostream>
#include <string>
using namespace std;

string find_answer(string message){
    string answers[5] = {
        "Sure", "Whoa, chill out!", "Calm down, I know what I am doing!", "Fine. Be that way!", "Whatever"
    };
    int lower_flag = 0;
    int question_flag = 0;
    
    if (message.find_first_not_of(' ') == string::npos || message == ""){
        return answers[3];
    }
    else{
        for (char i_char : message){
            if (isalpha(i_char) && tolower(i_char) == i_char){
                lower_flag = 1;
            }
            else if (i_char == '?'){
                question_flag = 1;
            }
        }
        
        if (lower_flag == 1 && question_flag == 0){
            return answers[4];
        }
        else if (lower_flag == 1 && question_flag == 1){
            return answers[0];
        }
        else if (lower_flag == 0 && question_flag == 0){
            return answers[1];
        }
        else if (lower_flag == 0 && question_flag == 1){
            return answers[2];
        }
    }
}

int main() {
    while (true){
        string text;
        cout << "Введите ваше сообщение: ";
        getline(cin, text);
        if (text == "goodbye"){
            cout << "Goodbye!" << endl;
            break;
        }
        else{
            cout << find_answer(text) << endl;
        }
    }
    return 0;
}