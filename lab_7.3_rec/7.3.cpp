#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void SortDiagonal(int** a, int n, int index = 0) {
    // ���� ����� �� ���� �������
    if (index >= n) return;

    // ����� ������� ������������� �������� �� �������, ��������� � index
    int maxIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (a[i][i] > a[maxIndex][maxIndex]) {
            maxIndex = i;
        }
    }

    // ������������ ������������� �������� �� �������
    if (maxIndex != index) {
        int temp = a[index][index];
        a[index][index] = a[maxIndex][maxIndex];
        a[maxIndex][maxIndex] = temp;
    }

    // ����������� ������ ��� ���������� �������� �� �������
    SortDiagonal(a, n, index + 1);
}

void PrintMatrix(int** a, int rowCount, int colCount, int rowNo = 0) {
    if (rowNo >= rowCount) return;

    for (int i = 0; i < colCount; i++) {
        cout << setw(4) << a[rowNo][i];
    }
    cout << endl;

    // ����������� ������ ��� ���������� �����
    PrintMatrix(a, rowCount, colCount, rowNo + 1);
}

int FindFirstNonPositiveRow(int** a, int rowCount, int colCount, int rowNo = 0) {
    // ������� �������: ���� �� ������� �� �����
    if (rowNo >= rowCount) return -1;

    bool hasPositive = false;
    for (int i = 0; i < colCount; i++) {
        if (a[rowNo][i] > 0) {
            hasPositive = true;
            break;
        }
    }

    // ���� � ����� ���� �������� ��������, ��������� ���� �����
    if (!hasPositive) return rowNo;

    // ����������� ������ ��� ���������� �����
    return FindFirstNonPositiveRow(a, rowCount, colCount, rowNo + 1);
}

int main() {
    srand((unsigned)time(NULL));
    int n;
    cout << "n: "; cin >> n;

    // �������� ��������� ��������� �������
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) {
            a[i][j] = rand() % 21 - 10; // ���������� ����������� ������� � ������� [-10, 10]
        }
    }

    cout << "Original Matrix:" << endl;
    PrintMatrix(a, n, n);

    // �������� ���������� ��� ���������� ������� �������
    SortDiagonal(a, n);

    cout << "Matrix after sorting diagonal:" << endl;
    PrintMatrix(a, n, n);

    // ��������� ����� ������� ����� ��� �������� ��������
    int firstNonPositiveRow = FindFirstNonPositiveRow(a, n, n);
    if (firstNonPositiveRow != -1) {
        cout << "First row with no positive elements: " << firstNonPositiveRow << endl;
    }
    else {
        cout << "All rows contain positive elements." << endl;
    }

    // ��������� ������� � ���'��
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
