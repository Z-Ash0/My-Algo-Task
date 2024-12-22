#include <iostream>
#include <vector>
using namespace std;

void heap(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heap(arr, n, largest);
    }
}

void heapSort(vector<int>& array) {
    int n = array.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heap(array, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heap(array, i, 0);
    }
}
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " " ;
        cout << endl;
}
int main() {
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    cout << "The Original array: \n";
    printArray(arr);

    heapSort(arr);

    cout << "\nThe array after sorting: \n";
    printArray(arr);

    return 0;
}
