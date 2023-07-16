#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort_recursive(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort_recursive(arr, low, pivot_index - 1);
        quicksort_recursive(arr, pivot_index + 1, high);
    }
}

void quicksort_iterative(vector<int>& arr, int low, int high) {
    stack<pair<int, int>> stk;
    stk.push(make_pair(low, high));
    while (!stk.empty()) {
        int l = stk.top().first;
        int h = stk.top().second;
        stk.pop();
        if (l < h) {
            int pivot = arr[h];
            int i = l - 1;
            for (int j = l; j <= h - 1; j++) {
                if (arr[j] < pivot) {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[i + 1], arr[h]);
            int p = i + 1;
            stk.push(make_pair(l, p - 1));
            stk.push(make_pair(p + 1, h));
        }
    }
}

int main() {
    int n = 100000;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }

    // Measure time taken for recursive quicksort
    auto start1 = high_resolution_clock::now();
    quicksort_recursive(arr, 0, n - 1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    // Reset the array to unsorted state
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }

    // Measure time taken for iterative quicksort
    auto start2 = high_resolution_clock::now();
    quicksort_iterative(arr, 0, n - 1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout << "Recursive quicksort took " << duration1.count() << " microseconds." << endl;
    cout << "Iterative quicksort took " << duration2.count() << " microseconds." << endl;

    return 0;
}
