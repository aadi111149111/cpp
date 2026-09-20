#include <iostream>
using namespace std;

int global_array[10];

int main() {
    int scores[10];
    int demo[4];
    static int stat[10];
    cout << "Local array:" << "[";
    for (int i = 0; i < 10; ++i) {
        cout << scores[i] << (i + 1 < 10 ? ", " : "");
    }
    cout << "]" << "\n";
    cout <<  "Global array:" << "[";
    for (int i = 0; i < 10; ++i) {
        cout << global_array[i] << (i + 1 < 10 ? ", " : "");
    }
    cout << "]" << "\n";
    cout <<  "Static array:" << "[";
    for (int i = 0; i < 10; ++i) {
        cout << stat[i] << (i + 1 < 10 ? ", " : "");
    }
    cout << "]" << "\n";
    // compute number of elements in the array
    int size = sizeof(scores) / sizeof(scores[0]);
    cout << "size=" << size << " (bytes=" << sizeof(scores) << ")";
    int nest[10] = {};
    cout <<  "zero array:" << "[";
    for (int i = 0; i < 10; ++i) {
        cout << nest[i] << (i + 1 < 10 ? ", " : "");
    }
    cout << "]" << "\n";
    // Valid uniform initialization
    int score[]{ 90, 85, 95 };
    cout <<  "first array:" << "[";
    for (int i = 0; i <3; ++i) {
        cout << score[i] << (i + 1 < 3 ? ", " : "");
    }
    cout << "]" << "\n";

    // ERROR: Narrowing conversion prevented! 
    // Standard initialization (=) would have silently chopped the .5 off.
    int preciseScores[]{ 90.5, 85, 95 };
    cout <<  "second array:" << "[";
    for (int i = 0; i < 3; ++i) {
        cout << preciseScores[i] << (i + 1 < 3 ? ", " : "");
    }
    cout << "]" << "\n";
    return 0;
}