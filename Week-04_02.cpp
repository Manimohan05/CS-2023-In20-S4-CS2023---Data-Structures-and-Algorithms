#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);

    int i = left, j = mid+1, k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            k++, i++;
        }
        else {
            temp[k] = arr[j];
            k++, j++;
        }
    }

    while (i <= mid) {
        temp[k] = arr[i];
        k++, i++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        k++, j++;
    }

    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
}

void mergeSort(vector<int>& arr) {
    int n = arr.size();
    for (int curr_size = 1; curr_size <= n-1; curr_size = 2*curr_size) {
        for (int left = 0; left < n-1; left += 2*curr_size) {
            int mid = min(left + curr_size - 1, n-1);
            int right = min(left + 2*curr_size - 1, n-1);

            merge(arr, left, mid, right);
        }
    }
}








void mergeRecursive(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortRecursive(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort1(arr, l, m);
        mergeSort1(arr, m + 1, r);

        merge1(arr, l, m, r);
    }
}






int main() {
    const int n = 19500;
    cout << "array size: " << n << endl;
    vector<int> arr(n);
    
    // seed the random number generator
    random_device rd;
    mt19937 gen(rd());    
    // generate random numbers between 1 and 100 and fill the vector
    uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
    }
    
    auto start = high_resolution_clock::now();
    mergeSort(arr);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds with iterative method" << endl;
    
    
    auto start1 = high_resolution_clock::now();
    mergeSort1(arr, 0, arr.size() - 1);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<chrono::microseconds>(end1 - start1);
    cout << "Time taken: " << duration1.count() << " microseconds with recursive method" << endl;
    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    

    return 0;
}