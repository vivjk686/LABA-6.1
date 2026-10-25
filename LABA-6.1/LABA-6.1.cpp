// LABA-6.1.cpp
// Шах Владислав Ігорьович
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом
// Варіант 32 (Рекурсивний спосіб)

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Рекурсивне формування масиву випадковими числами
void Create(int* b, const int size, const int Low, const int High, int i)
{
    b[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(b, size, Low, High, i + 1);
}

// Рекурсивне виведення елементів масиву
void Print(const int* b, const int size, int i)
{
    cout << setw(4) << b[i];
    if (i < size - 1)
        Print(b, size, i + 1);
    else
        cout << endl;
}

// Перевірка умови: всі, крім непарних кратних 3
// Тобто елемент задовольняє критерію, якщо він НЕ є (непарним і кратним 3)
bool Criterion(int element)
{
    return !(element % 2 != 0 && element % 3 == 0);
}

// Рекурсивне обчислення кількості елементів, що задовольняють критерію
int Count(const int* b, const int size, int i)
{
    if (i >= size)
        return 0;
    int current = Criterion(b[i]) ? 1 : 0;
    return current + Count(b, size, i + 1);
}

// Рекурсивне обчислення суми елементів, що задовольняють критерію
int Sum(const int* b, const int size, int i)
{
    if (i >= size)
        return 0;
    int current = Criterion(b[i]) ? b[i] : 0;
    return current + Sum(b, size, i + 1);
}

// Рекурсивна заміна нулями елементів, що задовольняють критерію
void Replace(int* b, const int size, int i)
{
    if (i >= size)
        return;
    if (Criterion(b[i]))
        b[i] = 0;
    Replace(b, size, i + 1);
}

#ifndef UNIT_TESTING
int main()
{
    srand((unsigned)time(NULL));

    const int n = 21;
    int b[n];
    const int Low = 10;
    const int High = 90;

    cout << "Lab 6.1 (Recursive) Variant 32" << endl;
    cout << "Criterion: all except odd multiples of 3" << endl << endl;

    Create(b, n, Low, High, 0);

    cout << "Initial array:" << endl;
    Print(b, n, 0);

    int count = Count(b, n, 0);
    int sum = Sum(b, n, 0);

    cout << "Count of elements satisfying criterion = " << count << endl;
    cout << "Sum of elements satisfying criterion   = " << sum << endl;

    Replace(b, n, 0);

    cout << "Modified array (criterion elements replaced with 0):" << endl;
    Print(b, n, 0);

    return 0;
}
#endif
