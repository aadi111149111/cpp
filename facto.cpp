// This is a program to find the factorial of a given number

#include <iostream>
using namespace std;

unsigned long long factorial(int a);
main()
{
    int fact; //variable declared for asked factorial
    cout << "Enter a number :";
    cin >> fact;
    if( fact < 0)
    {
        cout <<"Invalid input!!!!! You can't have factorial of negative number";
    }
    else if ( fact == 0 )
    {
        cout << "The factorial to zero is 1 ";
    }
    else
        cout << "The factorial of " << fact << " is: " << factorial(fact);
    return 0;
}

unsigned long long factorial( int a)
{
    if( a == 0 || a == 1)
        return 1;
    else
        return a * factorial(a - 1);
}