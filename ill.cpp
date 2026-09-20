#include <iostream>
using namespace std;

class Solution
{
public:
    void illus(int n)
    {
        for (int i = 1 ; i <= n ; i++ )
        {
            for (int j = 1 ; j <= i ; j++)
            {
                cout << i;
            }
            cout << endl;
        }
    }
};

int main()
{
    int number;
    cout << "Enter the number:";
    cin >> number;
    Solution sol1;
    sol1.illus(number);
    return 0;
}