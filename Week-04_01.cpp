#include <iostream>
#include <cstdlib>   // for rand() function
#include <ctime>     // for time() function
#include <chrono>

using namespace std;
 
 

int main() {
    

    // seed the random number generator
    srand(time(0));

    // specify the length of the array
    const int ARRAY_LENGTH = ;

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