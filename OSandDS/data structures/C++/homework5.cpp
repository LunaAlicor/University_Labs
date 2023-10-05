/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iostream>
#include <random>
#include <vector>
#include <stack>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;


template<typename T>
void block_sort(std::vector<T>& arr, bool reverse_flag, int& num_comparisons, int& num_swaps) {
    int n = arr.size();

    if (n == 0) {
        return;
    }

    if (std::is_integral<T>::value || std::is_floating_point<T>::value) {
        // Сортировка чисел
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                num_comparisons++;
                if ((!reverse_flag && arr[j] > arr[j + 1]) || (reverse_flag && arr[j] < arr[j + 1])) {
                    std::swap(arr[j], arr[j + 1]);
                    num_swaps++;
                }
            }
        }
    } else if (std::is_same<T, std::string>::value) {
        // Сортировка строк
        if (reverse_flag) {
            std::sort(arr.rbegin(), arr.rend());
        } else {
            std::sort(arr.begin(), arr.end());
        }
    }
}


template<typename T>
void bubble_sort(vector<T>& arr, bool reverse, int& num_comparisons, int& num_swaps) {
    int n = arr.size();
    if (n <= 1) {
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((arr[j] > arr[j + 1] && !reverse) || (arr[j] < arr[j + 1] && reverse)) {
                
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                num_swaps++;
            }
            num_comparisons++;
        }
    }
}



void fill_string_array(int n, vector<string>& arr) {
    random_device rd;
    mt19937 gen(rd());
    string char_set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    uniform_int_distribution<> char_dist(0, char_set.length() - 1);

    for (int i = 0; i < n; i++) {
        string random_string;
        int length = gen() % 10 + 1; 
        for (int j = 0; j < length; j++) {
            random_string += char_set[char_dist(gen)]; 
        }
        arr.push_back(random_string);
    }
}


template<typename T>
void quick_sort(vector<T>& arr, bool reverse, int& num_comparisons, int& num_swaps) {
    int n = arr.size();
    if (n <= 1) {
        return;
    }
    typename vector<T>::value_type pivot = arr[n / 2];
    vector<T> left, middle, right;
    for (int i = 0; i < n; i++) {
        if ((arr[i] < pivot && !reverse) || (arr[i] >= pivot && reverse)) {
            left.push_back(arr[i]);
        } else if (arr[i] == pivot) {
            middle.push_back(arr[i]);
        } else {
            right.push_back(arr[i]);
        }
        num_comparisons++;
    }
    quick_sort(left, reverse, num_comparisons, num_swaps);
    quick_sort(right, reverse, num_comparisons, num_swaps);
    arr.clear();
    for (int i = 0; i < left.size(); i++) {
        arr.push_back(left[i]);
        num_swaps++;
    }
    for (int i = 0; i < middle.size(); i++) {
        arr.push_back(middle[i]);
        num_swaps++;
    }
    for (int i = 0; i < right.size(); i++) {
        arr.push_back(right[i]);
        num_swaps++;
    }
}


void fill_array(int n, vector<int>& arr) {
random_device rd; 
mt19937 gen(rd()); 
uniform_int_distribution<> dis(-99, 99); 
for (int i = 0; i < n; i++) {
arr.push_back(dis(gen));
}
}

template<typename T>
void array_out(int n, vector<T>& arr){
    for (int i=0; i<n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}


void menu(int answer){
    int num_swaps=0;
    int num_comparisons=0;
    vector<int> arr;
    vector<string> str_arr;
    bool str_flag= false;
    bool reverse_flag;
    int answer2, answer3, n;
    cout<<"Чем заполняем массив?\n1-Числа\n2-строки\nВвод: ";
    cin>>answer2;
    cout<<"В обратном порядке?\n1-Да\n2-нет\nВвод: ";
    cin>>answer3;
    switch(answer3){
        case 1:
            reverse_flag = true;
            break;
        case 2:
            reverse_flag = false;
            break;
        default:
            break;
    }
    switch(answer2){
        case 1:
            cout<<"Введите размерность массива: ";
            cin>>n;
            fill_array(n, arr);
            cout<<"Вот ваш массив: ";
            array_out(n, arr);
            break;
        case 2: 
            str_flag = true;
            cout<<"Введите размерность массива: ";
            cin>>n;
            fill_string_array(n, str_arr);
            cout<<"Вот ваш массив: ";
            array_out(n, str_arr);
            break;
        default:
            cout<<"Ваш компьютер взорветься через: ";
            for (int i = 5; i != 0; i--) {
                std::cout <<"Взрыв через "<< i << std::endl;
            }
            cout<<"Бабах";
            break;
    }
    
    switch (answer){
        case 1:
            if (str_flag==true){
                bubble_sort(str_arr, reverse_flag, num_comparisons, num_swaps);
                cout<<"Отсортированный массив: ";
                array_out(n, str_arr);
                cout<<"Кол-во сравнений: "<<num_comparisons<<endl;
                cout<<"Кол-во перестановок: "<<num_swaps<<endl;
            }else{
                bubble_sort(arr, reverse_flag, num_comparisons, num_swaps);
                cout<<"Отсортированный массив: ";
                array_out(n, arr);
                cout<<"Кол-во сравнений: "<<num_comparisons<<endl;
                cout<<"Кол-во перестановок: "<<num_swaps<<endl;
            }
            break;
            
        case 2:
            if (str_flag==true){
                quick_sort(str_arr, reverse_flag, num_comparisons, num_swaps);
                cout<<"Отсортированный массив: ";
                array_out(n, str_arr);
                cout<<"Кол-во сравнений: "<<num_comparisons<<endl;
                cout<<"Кол-во перестановок: "<<num_swaps<<endl;
            }else{
                quick_sort(arr, reverse_flag, num_comparisons, num_swaps);
                cout<<"Отсортированный массив: ";
                array_out(n, arr);
                cout<<"Кол-во сравнений: "<<num_comparisons<<endl;
                cout<<"Кол-во перестановок: "<<num_swaps<<endl;
            }
            break;
        case 3:
            if (str_flag==true){
                block_sort(str_arr, reverse_flag, num_comparisons, num_swaps);
                cout<<"Отсортированный массив: ";
                array_out(n, str_arr);
                cout<<"Кол-во сравнений: "<<num_comparisons<<endl;
                cout<<"Кол-во перестановок: "<<num_swaps<<endl;
            }else{
                block_sort(arr, reverse_flag, num_comparisons, num_swaps);
                cout<<"Отсортированный массив: ";
                array_out(n, arr);
                cout<<"Кол-во сравнений: "<<num_comparisons<<endl;
                cout<<"Кол-во перестановок: "<<num_swaps<<endl;
            }
            break;
        default:
            cout<<"Ошибка ввода!";
            break;
        
    }
}


int main()
{
    int answer;
    cout<<"1-Бабл сорт \n2-Быстрая сортировка \n3-Блочная сортировка\n4-Выйти из программы\n";
    cout<<"Какая сортировка ?: ";
    cin>>answer;
    switch(answer){
        case 1:
            menu(answer);
            break;
        case 2:
            menu(answer);
            break;
        case 3:
            menu(answer);
            break;
        case 4:
            cout<<"Всего доброго!"<<endl;
            break;
        default:
            cout<<"Неправильное значение!\n";
            main();
            break;
    }
    return 0;
}