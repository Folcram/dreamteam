#include <vector>
#include <chrono>
#include <iostream>
using namespace std;
void merge(int* arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) {
        arr[i] = c[i];
    }
}
void merge_sorting(int* arr, int low, int high)
{
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sorting(arr, low, mid);
        merge_sorting(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}
void mergesort(){
int n;
    cin >> n;
    int* arr = new int(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    merge_sorting(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

}
void InsertionSort(){
        int n;
        cin >> n;
        int* arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            array[i] = rand();
        }
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

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << endl;
        }

}
void quicksorting(){
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand();
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
int partition(int* arr, int start, int end)
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
    if (start >= end) {
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
void heapSort()
{
      int n;
    cin >> n;
   int* arr = new arr[n];  
    for (int i = 0; i<n; n++){
        int b;
        b = rand();
        arr[i] = b;
    }
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
     for (int i = 0; i<l;i++){
    cout << arr[i] << endl;
}

int main()
{
  int k;
  setlocale(LC_ALL, "Rus");
  cout << "Введите номер сотрировки:" << endl;
  cout << "1 - heapsort" << end;
  cout << "2 - quicksort" << end;
  cout << "3 - InsertionSort" << end;
  cout << "4 - MergeSort" << endl;
   cin >> k;
     
     switch(k){
          case 1{
            heapSort();
            break;
          }
          case 2 {
          quicksorting();
          break;
          }
          case 3{
          InsertionSort();
          break;
          }
          case 4 {
          mergesort();
          break;
          }
     }        
}


