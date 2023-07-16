#include <iostream>
#include <cstdlib>   // for rand() function
#include <ctime>     // for time() function
#include <chrono>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void optimizedBubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            break;
        }
    }
}
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
  
        // Swap the found minimum element with the first element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    

    // seed the random number generator
    srand(time(0));

    // specify the length of the array
    const int ARRAY_LENGTH = 10;

    // create an array of random integers
    int random_array[ARRAY_LENGTH];
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        random_array[i] = rand() % 100;   // generate a random integer between 0 and 99
    }

    // print the array
    cout << "Random array: ";
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        cout << random_array[i] << ", ";
    }
    cout <<endl;

    // start the timer
    auto start = chrono::high_resolution_clock::now();

    insertionSort(random_array,ARRAY_LENGTH);
    bubbleSort(random_array,ARRAY_LENGTH);
    optimizedBubbleSort(random_array,ARRAY_LENGTH);
    selectionSort(random_array,ARRAY_LENGTH);
    // print the array
    cout << "Random array: ";
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        cout << random_array[i] << ", ";
    }
    cout <<endl;
     // stop the timer
    auto end = chrono::high_resolution_clock::now();

    // calculate the elapsed time
    auto elapsed_time = chrono::duration_cast<chrono::microseconds>(end - start);

    // print the elapsed time
    cout << "Elapsed time: " << elapsed_time.count() << "microseconds" << endl;

    return 0;
}