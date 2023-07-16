#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <stack>
#include <utility>

using namespace std;
using namespace chrono;


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

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}


void quicksort1(vector<int>& arr, int low, int high) {
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
    const int n = 500;
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
    quicksort(arr, 0, arr.size() - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken: " << duration.count() << " microseconds with quick sort recursive method " << endl;
    
    
    auto start1 = high_resolution_clock::now();
    quicksort1(arr, 0, arr.size() - 1);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<chrono::microseconds>(end1 - start1);
    cout << "Time taken: " << duration1.count() << " microseconds with iterative  quick sort method" << endl;
    
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    

    return 0;
}