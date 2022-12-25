#include <iostream>
#include <chrono>
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
int main()
{
  mergesort();  
}
