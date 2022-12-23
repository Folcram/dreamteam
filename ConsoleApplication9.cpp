#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;


int partition(int* a, int start, int end)
{
    int pivot = a[end];

    int pIndex = start;


    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }


    swap(a[pIndex], a[end]);
    return pIndex;
}

void quicksort(int* a, int start, int end)
{
   
    if (start >= end) {
        return;
    }

   
    int pivot = partition(a, start, end);

    quicksort(a, start, pivot - 1);

    
    quicksort(a, pivot + 1, end);
}

int main()
{
    int n;
    cin >> n;
    int* a = new int(n);
    for (int i = 0; i < n; i++) {
        a[i] = rand();
    }
    quicksort(a, 0, n - 1);

    // печатаем отсортированный массив
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}