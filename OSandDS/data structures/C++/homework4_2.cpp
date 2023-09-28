#include <iostream>
#include <array>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Реализация кольцевого буфера с использованием статического массива
template <size_t Size>
class FIFO {
public:
    FIFO() : front(0), rear(0) {}

    void Enqueue(int value) {
        if ((rear + 1) % Size == front) {
            cout << "Буфер переполнен" << endl;
        } else {
            buffer[rear] = value;
            rear = (rear + 1) % Size;
        }
    }

    int Dequeue() {
        if (front == rear) {
            cout << "Буфер пуст" << endl;
            return -1;
        } else {
            int value = buffer[front];
            front = (front + 1) % Size;
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
            cout << buffer[current] << " ";
            current = (current + 1) % Size;
        }
        cout << endl;
    }

    void CountDuplicates() {
        unordered_map<int, int> countMap;

        int current = front;
        while (current != rear) {
            countMap[buffer[current]]++;
            current = (current + 1) % Size;
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
            uniqueSet.insert(buffer[current]);
            current = (current + 1) % Size;
        }

        cout << "Неповторяющиеся элементы:" << endl;
        for (int element : uniqueSet) {
            cout << element << " ";
        }
        cout << endl;
    }

private:
    array<int, Size> buffer;
    size_t front;
    size_t rear;
};

int main() {
    constexpr size_t size = 5; // Задайте размер буфера здесь
    FIFO<size> buffer;

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
