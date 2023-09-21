// Задание: Удаление дубликатов из массива
// Описание: Напишите три программы, используя структуры данных
// std::array, std::vector и std::list, которые будут принимать входной
// массив (фиксированного размера для std::array и динамического для
// std::vector и std::list) и удалять все повторяющиеся элементы,
// оставляя только уникальные значения.
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <set>

using namespace std;


void removeDuplicates(int arr[], int& size) {
    if (size <= 1) {
        return;  
    }

    int newSize = 1;  

    for (int i = 1; i < size; ++i) {
        bool isDuplicate = false;

        
        for (int j = 0; j < newSize; ++j) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }

        
        if (!isDuplicate) {
            arr[newSize] = arr[i];
            ++newSize;
        }
    }

    size = newSize;
    
}


void arr_out(int arr[], int array_size){
    std::cout<<"Ваш массив: ";
    for (int i = 0; i < array_size; ++i) {
        std::cout << arr[i] << " ";
    }
}

void foo1() {
    int array_size;
    std::cout << "Введите размерность массива: ";
    std::cin >> array_size;

    int* arr = new int[array_size];

    for (int i = 0; i < array_size; ++i) {
        std::cout << "Введите элемент " << i << ": ";
        std::cin >> arr[i];
    }
    arr_out(arr, array_size);
    cout<<endl;
    removeDuplicates(arr, array_size);
    std::cout << "Новый массив ";
    arr_out(arr, array_size);
}


void foo2() {
    int* vector = nullptr;  
    int vector_size = 0;    
    int i_elem;

    std::cout << "Для остановки ввода введите -1" << std::endl;

    while (true) {
        std::cout << "Введите элемент " << vector_size + 1 << ": ";
        std::cin >> i_elem;

        if (i_elem == -1) {
            std::cout << "Остановка ввода." << std::endl;
            break;
        }

        int* new_vector = new int[vector_size + 1];
        
        for (int i = 0; i < vector_size; i++) {
            new_vector[i] = vector[i];
        }

        
        new_vector[vector_size] = i_elem;
        
        
        delete[] vector;
        
        
        vector = new_vector;
        vector_size++;
    }
    arr_out(vector, vector_size);
    removeDuplicates(vector, vector_size);
    cout<<"Удаляем дубликаты ";
    arr_out(vector, vector_size);
}


void foo3(){
    list<int> myList;
    int list_size = 0;

    cout << "Для остановки ввода введите -1: ";

    while (true) {
        int i_elem;
        cout<<endl;
        cout<<"Введите ваш элемент : ";
        cin >> i_elem;

        if (i_elem == -1) {
            cout << "Остановка ввода." << endl;
            break;
        }

        myList.push_back(i_elem);
        list_size++;
    }
    cout << "Элементы списка:" << endl;
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;
    cout<<"Удаляем дубликаты ";
    set<int> uniqueElements; 
    list<int>::iterator it = myList.begin();

    while (it != myList.end()) {
        if (uniqueElements.count(*it) > 0) {
            
            it = myList.erase(it);
        } else {
            uniqueElements.insert(*it);
            ++it;
        }
    }
    cout << "Элементы списка:" << endl;
    for (int num : myList) {
        cout << num << " ";
    }
}


int main()
{
    char answer;
    cout << "1-array, 2-vector, 3-list \n";
    cout << "Ввод: ";
    cin >> answer;

    
    switch (answer) {
        case '1': 
            foo1(); 
            break; 
        case '2':
            foo2();
            break;
        case '3':
            foo3();
            break;
        default:
            cout << "Неправильное значение! \n";
            main();
            break;
    }

    return 0;
}