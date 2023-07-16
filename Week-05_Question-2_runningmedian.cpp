#include <iostream>
#include <vector>
using namespace std;

// Merge function to merge two sorted arrays
vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        }
        else {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

// Merge sort function to sort an array
vector<int> mergeSort(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) {
        return arr;
    }

    int mid = n / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}


// void userInput()
// {
//     int size=5;
//     int arr[size];
//     cout<<"Enter array elements"<<endl;
//     for(int i=0;i<size;i++)
//     {
//         cin>>arr[i];
//     }

//     cout<<"Array elements are:"<<endl;
//     for(int i=0;i<size;i++)
//         cout<<arr[i]<<" ";
//     cout<<endl;
// }


int main() {
    int size1;
    cin>>size1;
    int* arr1 = new int[size1];
    cout<<"Enter array elements"<<endl;
    for(int i=0;i<size1;i++)
    {
        cin>>arr1[i];
    }

    std::vector<int> arr(arr1, arr1 + size1);

    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
    vector<int> sortedArr;
    double median = 0;
    
   cout << "median" << "      sorted"<<endl;
    for (int i = 0; i < arr.size(); i++) {
        // Add the i-th element to the sorted array
        sortedArr.push_back(arr[i]);

        // Sort the updated array using merge sort
        sortedArr = mergeSort(sortedArr);

        // Calculate the median
        int n = sortedArr.size();
        if (n % 2 == 0) {
            median = (double)(sortedArr[n/2 - 1] + sortedArr[n/2]) / 2.0;
        }
        else {
            median = sortedArr[n/2];
        }

        // Print the updated median
        
        cout << "[";
        for (int j = 0; j < sortedArr.size(); j++) {
            cout << sortedArr[j];
            if (j != sortedArr.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]        "  << median << endl;
    }

    return 0;
}
