
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Array {
private:
    long* arr;
    int size;

public:
    // Конструктор за замовчуванням
    Array() {
        size = 0;
        arr = nullptr;
    }

    // Конструктор із заданим розміром
    Array(int n) {
        if (n < 0) n = 0;

        size = n;
        arr = (size > 0) ? new long[size]() : nullptr;
    }

    // Конструктор копіювання
    Array(const Array& other) {
        size = other.size;
        arr = (size > 0) ? new long[size] : nullptr;

        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Оператор присвоєння
    Array& operator=(const Array& other) {
        if (this != &other) {
            long* temp = (other.size > 0)
                ? new long[other.size]
                : nullptr;

            for (int i = 0; i < other.size; i++) {
                temp[i] = other.arr[i];
            }

            delete[] arr;
            arr = temp;
            size = other.size;
        }
        return *this;
    }

    // Деструктор
    ~Array() {
        delete[] arr;
    }

    // Заповнення з клавіатури
    void Input() {
        for (int i = 0; i < size; i++) {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
    }

    // Заповнення випадковими числами
    void RandomFill() {
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 201 - 100;
        }
    }

    // Заповнення значенням за замовчуванням
    void DefaultFill() {
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    // Виведення масиву
    void Show() const {
        if (size == 0) {
            cout << "Masiv porozhniy!\n";
            return;
        }

        cout << "Masiv: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Додавання елемента в кінець
    void Add(long value) {
        long* temp = new long[size + 1];

        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        temp[size] = value;

        delete[] arr;
        arr = temp;
        size++;
    }

    // Видалення за індексом
    void DeleteByIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Pomylka: nepravylnyi indeks!\n";
            return;
        }

        long* temp = (size > 1) ? new long[size - 1] : nullptr;

        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) {
                temp[j++] = arr[i];
            }
        }

        delete[] arr;
        arr = temp;
        size--;
    }

    // Видалення за значенням (перший збіг)
    void DeleteByValue(long value) {
        int index = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Element ne znaideno!\n";
            return;
        }

        DeleteByIndex(index);
    }

    // Сортування: true - за зростанням
    // false - за спаданням
    void Sort(bool ascending = true) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                bool needSwap = ascending
                    ? arr[j] > arr[j + 1]
                    : arr[j] < arr[j + 1];

                if (needSwap) {
                    long temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Мінімальне значення
    long Min() const {
        if (size == 0) {
            cout << "Masiv porozhniy!\n";
            return 0;
        }

        long result = arr[0];

        for (int i = 1; i < size; i++) {
            if (arr[i] < result) {
                result = arr[i];
            }
        }

        return result;
    }

    // Максимальне значення
    long Max() const {
        if (size == 0) {
            cout << "Masiv porozhniy!\n";
            return 0;
        }

        long result = arr[0];

        for (int i = 1; i < size; i++) {
            if (arr[i] > result) {
                result = arr[i];
            }
        }

        return result;
    }

    // Середнє арифметичне
    double Average() const {
        if (size == 0) {
            cout << "Masiv porozhniy!\n";
            return 0;
        }

        double sum = 0;

        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }

        return sum / size;
    }

    // Отримання розміру масиву
    int GetSize() const {
        return size;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    Array a(5);

    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Vvesty elementy\n";
        cout << "2. Vypadkove zapovnennia\n";
        cout << "3. Zapovnити nuliamy\n";
        cout << "4. Pokazaty masiv\n";
        cout << "5. Dodaty element\n";
        cout << "6. Vydalyty za indeksom\n";
        cout << "7. Vydalyty za znachennyam\n";
        cout << "8. Sortuvaty za zrostanniam\n";
        cout << "9. Sortuvaty za spadanniam\n";
        cout << "10. Minimalne znachennia\n";
        cout << "11. Maksymalne znachennia\n";
        cout << "12. Serednie arifmetychne\n";
        cout << "13. Rozmir masyvu\n";
        cout << "0. Vykhid\n";
        cout << "Vybir: ";

        if (!(cin >> choice)) {
            cout << "Pomylka vvedennia!\n";
            break;
        }

        long value;
        int index;

        switch (choice) {
        case 1:
            a.Input();
            break;

        case 2:
            a.RandomFill();
            cout << "Masiv zapovneno!\n";
            break;

        case 3:
            a.DefaultFill();
            cout << "Masiv zapovneno nuliamy!\n";
            break;

        case 4:
            a.Show();
            break;

        case 5:
            cout << "Vvedit element: ";
            cin >> value;
            a.Add(value);
            break;

        case 6:
            cout << "Vvedit indeks (vid 0): ";
            cin >> index;
            a.DeleteByIndex(index);
            break;

        case 7:
            cout << "Vvedit znachennia: ";
            cin >> value;
            a.DeleteByValue(value);
            break;

        case 8:
            a.Sort(true);
            cout << "Masiv vidsortovano za zrostanniam!\n";
            break;

        case 9:
            a.Sort(false);
            cout << "Masiv vidsortovano za spadanniam!\n";
            break;

        case 10:
            if (a.GetSize() > 0)
                cout << "Minimum: " << a.Min() << endl;
            else
                cout << "Masiv porozhniy!\n";
            break;

        case 11:
            if (a.GetSize() > 0)
                cout << "Maksimum: " << a.Max() << endl;
            else
                cout << "Masiv porozhniy!\n";
            break;

        case 12:
            if (a.GetSize() > 0)
                cout << "Serednie: " << a.Average() << endl;
            else
                cout << "Masiv porozhniy!\n";
            break;

        case 13:
            cout << "Rozmir: " << a.GetSize() << endl;
            break;

        case 0:
            cout << "Zavershennia programy.\n";
            break;

        default:
            cout << "Nepravильnyi vybir!\n";
        }

    } while (choice != 0);

    return 0;
}

