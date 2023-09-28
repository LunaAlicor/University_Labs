/******************************************************************************

Напишите три программы: реализуйте кольцевой буфер с использованием
статического массива и контейнеров std::array и std::vector. В каждой из
программ используйте разные структуры данных из приведенных. Кольцевой
буфер должен являться обособленной структурой или функциями
использующие структуру (никаких % в main быть не должно, иначе
снижение баллов).

*******************************************************************************/
#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Реализация кольцевого буфера с использованием динамического массива
class FIFO {
public:
    FIFO(int size) {
        body = new int[size];
        this->size = size;
        front = 0;
        rear = 0;
    }

    ~FIFO() {
        delete[] body;
    }

    void Enqueue(int value) {
        if ((rear + 1) % size == front) {
            cout << "Буфер переполнен" << endl;
        } else {
            body[rear] = value;
            rear = (rear + 1) % size;
        }
    }

    int Dequeue() {
        if (front == rear) {
            cout << "Буфер пуст" << endl;
            return -1;
        } else {
            int value = body[front];
            front = (front + 1) % size;
            return value;
        }
    }

    void PrintBuffer() {
        int current = front;
        if (front == rear) {
            cout << "Буфер пуст" << endl;
            return;
        }
        cout << "Содержимое буфера: ";
        while (current != rear) {
            cout << body[current] << " ";
            current = (current + 1) % size;
        }
        cout << endl;
    }
    
    
    void CountDuplicates() {
        unordered_map<int, int> countMap; 

        int current = front;
        while (current != rear) {
            countMap[body[current]]++;
            current = (current + 1) % size;
        }

        cout << "Повторяющиеся элементы и их количество:" << endl;
        for (const auto& pair : countMap) {
            if (pair.second > 1) {
                cout << pair.first << ": " << pair.second << " раз" << endl;
            }
        }
    }
    
    
    void PrintUniqueElements() {
        unordered_set<int> uniqueSet; 

        int current = front;
        while (current != rear) {
            uniqueSet.insert(body[current]);
            current = (current + 1) % size;
        }

        cout << "Неповторяющиеся элементы:" << endl;
        for (int element : uniqueSet) {
            cout << element << " ";
        }
        cout << endl;
    }
    
    

private:
    int* body;
    int size;
    int front;
    int rear;
};

int main() {
    int size;
    cout << "Введите размерность кольцевого буфера: ";
    cin >> size;
    FIFO buffer(size);

    int choice;
    do {
        cout << "Выберите операцию:\n";
        cout << "1. Добавить элемент в буфер (Enqueue)\n";
        cout << "2. Извлечь элемент из буфера (Dequeue)\n";
        cout << "3. Вывести содержимое буфера\n";
        cout << "4. Посчитать повторяющиеся элементы\n";
        cout << "5. Вывести уникальные элементы\n";
        cout << "0. Выйти из программы\n";
        cin >> choice;

switch (choice) {
        case 1: {
            int value;
            cout << "Введите значение для добавления: ";
            cin >> value;
            buffer.Enqueue(value);
            break;
        }
        case 2: {
            int value = buffer.Dequeue();
            if (value != -1) {
                cout << "Извлеченное значение: " << value << endl;
            }
            break;
        }
        case 3: {
            buffer.PrintBuffer();
            break;
        }
        case 4: {
            buffer.CountDuplicates();
            break;
        }
        case 5: {
            buffer.PrintUniqueElements();
            break;
        }
        case 0: {
            cout << "Выход из программы." << endl;
            break;
        }
        default: {
            cout << "Некорректный выбор операции. Попробуйте снова." << endl;
            break;
        }
    }
    } while (choice != 0);

    return 0;
}

