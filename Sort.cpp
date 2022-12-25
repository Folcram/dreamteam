#include <iostream>
#include <chrono>
using namespace std;
//Сортировка Шелла
void shellSort(int* arr, const int& n)
{
    for (int shag = n / 2; shag > 0; shag /= 2)
    {
        for (int i = shag; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= shag && arr[j - shag] > temp; j -= shag)
            {
                arr[j] = arr[j - shag];
            }
            arr[j] = temp;
        }
    }
}
// доп. функция для сортировки слиянием
void merge(int* arr, int low, int high, int mid)
{
    int i, j, k;
    int* c = new int[high];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            c[k] = arr[i];
            //эти счетчики необходимы для смены индекса элемента сотрируемого массива
            k++;
            i++;
        }
        else
        {
            c[k] = arr[j];
            //эти счетчики необходимы для смены индекса элемента сотрируемого массива
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
    {
        arr[i] = c[i];
    }
}
// сортировка слиянием
void merge_sorting(int* arr, int low,  int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sorting(arr, low, mid);
        merge_sorting(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}
// сортировка вставками
void InsertionSort(int* arr, const int& n)
{
    for (int k = 1; k < n; k++)
    {
        int temp = arr[k];
        int j = k - 1;
        while (j >= 0 && temp <= arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}
// доп. функция для быстрой сортировки
int partition(int* arr, const int& start, const int& end)
{
    int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[end]);
    return pIndex;
}
// функция  быстрой сортировки
void quicksort(int* arr, int start, int end)
{
    
    if (start >= end)
    {
        return;
    }
    int pivot = partition(arr, start, end);
    quicksort(arr, start, pivot - 1);
    quicksort(arr, pivot + 1, end);
}
//доп. функция  пирамидальной сортировки
void heapify(int* arr, int n, int root)
{
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != root)
    {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}
// функция  пирамидальной сортировки
void heapSort(int* arr, const int& n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    // Рандомим размер и элементы массива
    int size;
     size = rand();
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
    int numbermenu;
    setlocale(LC_ALL, "Rus");
    cout << "Введите номер сотрировки:" << endl;
    cout << "1 - heapsort" <<  endl;
    cout << "2 - quicksort" <<  endl;
    cout << "3 - InsertionSort" << endl;
    cout << "4 - MergeSort" << endl;
    cout << "5 - ShellSort" << endl;
    // В зависимости от набраного numbermenu в switch-case вызвается функция сортировки
    cin >> numbermenu;
    switch (numbermenu)
    {
    case 1:
        {
        char otvet;
        cout << "хотите вызвать сортировку 10к раз y/n" << endl;
        cin >> otvet;
        
        if (otvet == 'y')
        {
            auto startobh = std::chrono::steady_clock::now();
            for (int i = 0; i < 10000; i++) 
            {
               
                int size;
                size = rand();
                int* arr = new int[size];
                for (int i = 0; i < size; i++)
                {
                    arr[i] = rand();
                }
                auto start = std::chrono::steady_clock::now();
                heapSort(arr, size);
                auto end = std::chrono::steady_clock::now();
                std::cout << "время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "mс" << endl;
            }
            auto endobh = std::chrono::steady_clock::now();
            std::cout << " Общее время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(endobh - startobh).count() << "mс" << endl;
            break;
        }
        else 
        {
            auto startobh = std::chrono::steady_clock::now();
            heapSort(arr, size);
            auto endobh = std::chrono::steady_clock::now();
            std::cout << " время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(endobh - startobh).count() << "mс" << endl;
            break;
        }
        }
    case 2:
        {
        char otvet;
        cout << "хотите вызвать сортировку 10к раз y/n" << endl;
        cin >> otvet;

        if (otvet == 'y')
        {
            auto startobh = std::chrono::steady_clock::now();
            for (int i = 0; i < 10000; i++) 
            {

                int size;
                size = rand();
                int* arr = new int[size];
                for (int i = 0; i < size; i++)
                {
                    arr[i] = rand();
                }
                auto start = std::chrono::steady_clock::now();
                quicksort(arr, 0, size -1);
                auto end = std::chrono::steady_clock::now();
                std::cout << "время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "mс" << endl;
            }
            auto endobh = std::chrono::steady_clock::now();
            std::cout << " Общее время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(endobh - startobh).count() << "mс" << endl;
            break;
        }
        else 
        {
            auto startobh = std::chrono::steady_clock::now();
            quicksort(arr, 0, size - 1);
            auto endobh = std::chrono::steady_clock::now();
            std::cout << " время сортировки: " << std::chrono::duration_cast<std::chrono::microseconds>(endobh - startobh).count() << "mкс";
            break;
        }
            
        }
    case 3:
        {
        char otvet;
        cout << "хотите вызвать сортировку 10к раз y/n" << endl;
        cin >> otvet;

        if (otvet == 'y')
        {
            auto startobh = std::chrono::steady_clock::now();
            for (int i = 0; i < 10000; i++)
            {

                int size;
                size = rand();
                int* arr = new int[size];
                for (int i = 0; i < size; i++)
                {
                    arr[i] = rand();
                }
                auto start = std::chrono::steady_clock::now();
                InsertionSort(arr, size);
                auto end = std::chrono::steady_clock::now();
                std::chrono::duration<double> sec = end - start;
                std::cout << "время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "mс" << endl;
            }
            auto endobh = std::chrono::steady_clock::now();
            std::cout << " Общее время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(endobh - startobh).count() << "mс" << endl;
       
            break;
        }
        else
        {
            auto startobh = std::chrono::steady_clock::now();
            InsertionSort(arr, size);
            auto endobh = std::chrono::steady_clock::now();
            std::cout << "время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(endobh - startobh).count() << "mc";
            break;
        }
        }
    case 4:
        {
        char otvet;
        cout << "хотите вызвать сортировку 10к раз y/n" << endl;
        cin >> otvet;

        if (otvet == 'y')
        {
            auto startobh = std::chrono::steady_clock::now();
            for (int i = 0; i < 10000; i++)
            {

                int size;
                size = rand();
                int* arr = new int[size];
                for (int i = 0; i < size; i++)
                {
                    arr[i] = rand();
                }
                auto start = std::chrono::steady_clock::now();
                merge_sorting(arr, 0, size - 1);
                auto end = std::chrono::steady_clock::now();
                std::cout << " Общее время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "mс" << endl;
            }
            auto endobh = std::chrono::steady_clock::now();
            std::cout << " Общее время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(endobh - startobh).count() << "с" << endl;
            break;
        }
        else
        {
            auto startobh = std::chrono::steady_clock::now();
            merge_sorting(arr, 0, size -1);
            auto endobh = std::chrono::steady_clock::now();
            std::cout << "время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(endobh - startobh).count() << "mс" << endl;
            break;
        }
        }
    case 5:
        {
        char otvet;
        cout << "хотите вызвать сортировку 10к раз y/n" << endl;
        cin >> otvet;

        if (otvet == 'y')
        {
            auto startobh = std::chrono::steady_clock::now();
            for (int i = 0; i < 10000; i++)
            {

                int size;
                size = rand();
                int* arr = new int[size];
                for (int i = 0; i < size; i++)
                {
                    arr[i] = rand();
                }
                auto start = std::chrono::steady_clock::now();
                shellSort(arr, size);
                auto end = std::chrono::steady_clock::now();
                std::cout << " время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "mс" << endl;
            }
            auto endobh = std::chrono::steady_clock::now();
            
            std::cout << "Общее время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>( endobh - startobh).count() << "mс" << endl;
            break;
        }
        else
        {
            auto startobh = std::chrono::steady_clock::now();
            shellSort(arr, size);
            auto endobh = std::chrono::steady_clock::now();
            std::chrono::duration<double> sec = endobh - startobh;
            std::cout << "время сортировки: " << std::chrono::duration_cast<std::chrono::milliseconds>(endobh - startobh).count() << "mс" << endl;
            break;
        }
        }
        // если выбран не тот номер то вызывается ошибка
    default:
        {
            cout << "Ошибка" << endl;
        }
    }
    return 0;
}



