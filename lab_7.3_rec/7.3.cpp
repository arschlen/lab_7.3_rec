#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void SortDiagonal(int** a, int n, int index = 0) {
    // якщо дійшли до кінця діагоналі
    if (index >= n) return;

    // Пошук індексу максимального елемента на діагоналі, починаючи з index
    int maxIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (a[i][i] > a[maxIndex][maxIndex]) {
            maxIndex = i;
        }
    }

    // Перестановка максимального елемента на позицію
    if (maxIndex != index) {
        int temp = a[index][index];
        a[index][index] = a[maxIndex][maxIndex];
        a[maxIndex][maxIndex] = temp;
    }

    // Рекурсивний виклик для наступного елемента на діагоналі
    SortDiagonal(a, n, index + 1);
}

void PrintMatrix(int** a, int rowCount, int colCount, int rowNo = 0) {
    if (rowNo >= rowCount) return;

    for (int i = 0; i < colCount; i++) {
        cout << setw(4) << a[rowNo][i];
    }
    cout << endl;

    // Рекурсивний виклик для наступного рядка
    PrintMatrix(a, rowCount, colCount, rowNo + 1);
}

int FindFirstNonPositiveRow(int** a, int rowCount, int colCount, int rowNo = 0) {
    // Базовий випадок: якщо ми пройшли всі рядки
    if (rowNo >= rowCount) return -1;

    bool hasPositive = false;
    for (int i = 0; i < colCount; i++) {
        if (a[rowNo][i] > 0) {
            hasPositive = true;
            break;
        }
    }

    // Якщо у рядку немає додатних елементів, повертаємо його номер
    if (!hasPositive) return rowNo;

    // Рекурсивний виклик для наступного рядка
    return FindFirstNonPositiveRow(a, rowCount, colCount, rowNo + 1);
}

int main() {
    srand((unsigned)time(NULL));
    int n;
    cout << "n: "; cin >> n;

    // Динамічне створення квадратної матриці
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 21 - 10; // Заповнення випадковими числами в діапазоні [-10, 10]
        }
    }

    cout << "Original Matrix:" << endl;
    PrintMatrix(a, n, n);

    // Виконуємо сортування для заповнення головної діагоналі
    SortDiagonal(a, n);

    cout << "Matrix after sorting diagonal:" << endl;
    PrintMatrix(a, n, n);

    // Знаходимо номер першого рядка без додатних елементів
    int firstNonPositiveRow = FindFirstNonPositiveRow(a, n, n);
    if (firstNonPositiveRow != -1) {
        cout << "First row with no positive elements: " << firstNonPositiveRow << endl;
    }
    else {
        cout << "All rows contain positive elements." << endl;
    }

    // Видалення матриці з пам'яті
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
