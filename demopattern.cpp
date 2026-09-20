#include <iostream>
using namespace std;


class Solution {
public:
    void pattern4(int n) 
    {
        for (int i = 0; i <= n ; i++)
        {
            for (int j = 0 ; j < i ; j++)
            {
                cout << "*";
            }
            for (int k = 0 ; k < 2*n-2*i ; k++)
            {
                cout << " " ;
            }
            for (int j = 0 ; j < i ; j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
    }
};

int main()
{
    int num ;
    cout << "Enter the number " << std::endl;
    cin >> num;
    Solution sol1;
    cout << "The pattern is:" << "\n";
    sol1.pattern4(num) ;
    return 0;
}