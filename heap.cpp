#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    // if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if largest is not root
    if (largest != root)
    {
        swap(arr[root], arr[largest]);
        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--)
    {
        // move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
   //modified for all array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int heap_arr[n];
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> heap_arr[i];

    cout << "Input array:\n";
    displayArray(heap_arr, n);

    heapSort(heap_arr, n);

    cout << "Sorted array:\n";
    displayArray(heap_arr, n);
}
