#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int x = 2;
    int *y = &x;
    int **z = &y;
    cout << x << "\n" ;
    cout << x << " " << y << "\n";
    cout << x << " " << y << " " << *y << "\n";
    cout << x << " " << y << " " << *y  << " " << **z << "\n" ;
    cout << x << " " << y << " " << *y  << " " << **z  << " " << z << " " <<  *z  << "\n";
    return 0;
    vector<int> *arr[1]{};

}