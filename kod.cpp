#include <iostream>
#include <locale>
using namespace std;

// Быстрая сортировка
int section(int mas[], int start, int end)
{
    int point = mas[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (mas[i] <= point)
            count++;
    }
    // Придание поворотному элементу правильного положения
    int index = start + count;
    swap(mas[index], mas[start]);
    // Сортировка левой и правой частей поворотного элемента
    int i = start, j = end;
    while (i < index && j > index)
    {
        while (mas[i] <= point)
            i++;
        while (mas[j] > point)
            j--;
        if (i < index && j > index)
            swap(mas[i++], mas[j--]);
    }
    return index;
}
void sortirovka(int mas[], int start, int end)
{
    // базовый корпус
    if (start >= end)
        return;
    // разбиение массива на разделы
    int p = section(mas, start, end);
    // Сортировка левой части
    sortirovka(mas, start, p - 1);
    // Сортировка правой части
    sortirovka(mas, p + 1, end);
}

// Сортировка слиянием
void sort(int*, int, int, int);
void _sortirovka_(int* arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        _sortirovka_(arr, low, mid);
        _sortirovka_(arr, mid + 1, high);
        sort(arr, low, high, mid);
    }
}
void sort(int* arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            c[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
        arr[i] = c[i];
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    do
    {
        cout << "Введите размерность массива: ";
        cin >> n;
        if (n <= 0)
            cout << "Ошибка" << endl;
    }
    while (n <= 0);

    int mas[100];
    cout << "Введите массив: ";
    for (int i = 0; i < n; i++)
        cin >> mas[i];
    int vibor;

    do
    {
        cout << endl << "1 - быстрая сортировка" << endl << "2 - сортировка слиянием" << endl << "Выберите способ сортировки: ";
        cin >> vibor;
        if (vibor != 1 && vibor != 2)
            cout << "Ошибка" << endl;
    }
    while (vibor != 1 && vibor != 2);
    
    switch (vibor)
    {
        case 1:
            sortirovka(mas, 0, n - 1);
            cout << "Отсортированный массив: ";
            for (int i = 0; i < n; i++)
                cout << mas[i] << " ";
            break;
        case 2:
            _sortirovka_(mas, 0, n - 1);
            cout << "Отсортированный массив: ";
            for (int i = 0; i < n; i++)
                cout << mas[i] << " ";
            break;
    }
}