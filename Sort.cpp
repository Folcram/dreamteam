#include <iostream>
using namespace std;
void shellSort(int* arr, const int& n)
{
    for (int l = n / 2; l > 0; l /= 2)
    {
        for (int i = l; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= l && arr[j - l] > temp; j -= l)
            {
                arr[j] = arr[j - l];
            }
            arr[j] = temp;
        }
    } 
}
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
    {
        arr[i] = c[i];
    }
}
void merge_sorting(int* arr, int low, int high)
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
void InsertionSort(int* arr, const int& n)
{
    for (int k = 1; k < n; k++)
    {
        int temp = arr[k];
        int j = k - 1;
        while (j >= 0 && temp <= array[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}
int partition(int* arr, const int& start,const int& end)
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
    for (int i = 0; i < l; i++) 
    {
        cout << arr[i] << endl;
    }
}
int main()
 {
        int size = rand();
        int* arr = new int[size];
        for (int i = 0; i < size(); i++) 
        {
            arr[i] = rand();
        }
        int numbermenu;
        setlocale(LC_ALL, "Rus");
        cout << "Введите номер сотрировки:" << endl;
        cout << "1 - heapsort" << end;
        cout << "2 - quicksort" << end;
        cout << "3 - InsertionSort" << end;
        cout << "4 - MergeSort" << endl;
        cout << "5 - ShellSort" << endl;
        cin >> numbermenu;
        switch (numbermenu) 
        {
            case 1
            {
                heapSort(arr, size);
                break;
            }
            case 2 
            {
                quicksort(arr, 0, size - 1);
                break;
            }
            case 3
            {
                InsertionSort(arr, size);
                break;
            }
            case 4 
            {
                merge_sorting(arr, 0, size - 1);
                break;
            }
            case 5 
            {
                shellSort(arr, size);
                break;
            }
            default 
            {
                cout << "Ошибка" << endl;
            }
        }
        return 0;
}



