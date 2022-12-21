#include <iostream>  
#include <vector>
#include <chrono>
using namespace std;

// реализация сортировки Шелла
int shellSort(vector <int> arr, int N)
{
    for (int gap = N / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < N; i += 1)
        {
            //сортировка подсписков, созданных с помощью gap 
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    return 0;
}

int main()
{
    vector <int> arr(10000000);
    //Вычислить размер массива 
    for (int i = 0; i < arr.size(); i++)
        arr[i] = rand();
    auto start = chrono::steady_clock::now();
    shellSort(arr, arr.size());
    auto end = chrono::steady_clock::now();
    cout << "\nArray after shell sort: \n";
    cout << "Elapsed time in seconds: "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec";

    return 0;
}
