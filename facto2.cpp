#include <iostream>
using namespace std;

unsigned long long factorial(int a);

int main() {
    int fact;
    cout << "Enter a number: ";
    cin >> fact;
    
    if (fact < 0) {
        // Handle the error cleanly in main, before doing any math
        cout << "Invalid input! You can't have a factorial of a negative number." << endl;
    } else {
        cout << "The factorial of " << fact << " is: " << factorial(fact) << endl;
    }
    return 0;
}

unsigned long long factorial(int a) {
    // Base case: 0! is 1
    if (a == 0) {
        return 1;
    }
    // Recursive case: a * (a-1)!
    return a * factorial(a - 1);
}