#include <iostream>
using namespace std;

class Solution1 {
public:
    void pattern1(int n) 
    {
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {  
                  cout << "*";
            }
        cout << "\n";
        }
    }

};
class Solution2 {
public:
    void pattern2(int n) {
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < i+1 ; j++)
            {
                cout << "*";
            }
            cout << "\n";
        }

    }
};
class Solution3 {
public:
    void pattern3(int n) {
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 1 ; j < i+2 ; j++ )
            {
                cout << j;
            }
            cout << "\n";
        }

    }
};
class Solution4 {
public:
    void pattern4(int n) {
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 0 ; j < i ; j++ )
            {
                cout << i;
            }
            cout << "\n";
        }

    }
};
class Solution5 {
public:
    void pattern5(int n)
    {
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0; j < n-i; j++ )
            {
                cout << "*";
            }
            cout << "\n";
        }
    }
};
class Solution6 {
public:
    void pattern6(int n)
    {
        for (int i=1 ; i <= n ; i++)
        {
            for(int j=1 ; j <= n+1-i ; j++)
            {
                cout << j;
            }
            cout << "\n";
        }
    }
};
class Solution7 {
public:
    void pattern7(int n) 
    {
      for (int i = 0; i < n ; i++)
      {
        for (int j = 0 ; j < n-i-1 ; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2*i+1; k++)
        {
            cout << "*";
        }
        cout << "\n";
      }
    }
};
class Solution8 {
public:
    void pattern8(int n)
    {
        for (int i = 0; i <= n; i++ )
        {
            for (int j = 0; j < i ; j++)
            {
                cout << " ";
            }
            for (int k = 0; k < 2*n-(2*i+1) ; k++)
            {
                cout << "*";
            }
            cout << "\n";
        }
    }
};
class Solution9 {
public:
    void pattern9(int n)
    {
        for (int i = 1 ; i < n+1 ; i++)
        {
            for (int k = 0 ; k <= n-i-1 ; k++ )
            {
                cout << " ";
            }
            for (int l = 0 ; l < 2*i-1 ; l++ )
            {
                cout << "*";
            }
            cout << "\n";
        }
        for (int i = 0; i <= n; i++ )
        {
            for (int j = 0; j < i ; j++)
            {
                cout << " ";
            }
            for (int k = 0; k < 2*n-(2*i+1) ; k++)
            {
                cout << "*";
            }
            cout << "\n";
        }
    }
};
class Solution10{
public:
    void pattern10(int n) {
       for (int i = 0; i < n ; i++)
        {
            for (int j = 0 ; j <= i ; j++)
            {
                cout << "*";
            }
            cout << "\n";
        } 
        for (int i = 1; i < n ; i++)
        {
            for (int j = 0 ; j < n-i ; j++)
            {
                cout << "*" ;
            }
            cout << "\n";
        }

    }
};
class Solution11{
public:
    void pattern11(int n) {
        for(int i = 0; i < n; i++)
        {
             int init = 0;
            for(int j = 0; j<= i; j++)
            {
            }
            cout << "\n";
        }
    }
};
class Solution13{
public:
    int init = 1;
    void pattern13(int n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i; j++ )
            {
                cout << init << " ";
                init++;
            }
            cout << "\n";
        }
    }
};
class Solution14{
public:
    void pattern14(int n)
    {
        string arr[26] = {"A", "B", "C", "D", "E"};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << arr[j];
            }
            cout << "\n";
        }
    }
};
class Solution15{
public:    
    void pattern15(int n)
    {
        string arr[26] = {"A", "B", "C", "D", "E"};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n-i; j++)
            {
                cout << arr[j];
            }
            cout << "\n";
        }
    }
};
class Solution16{
public:    
    void pattern16(int n)
    {
        string arr[26] = {"A", "B", "C", "D", "E"};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << arr[i];
            }
            cout << "\n";
        }
    }
};
class Solution17{
public:    
    void pattern17(int n)
    {

    }
};
class Solution20{
public:
    void pattern20(int n)
    {
        for (int i = 1; i <= n ; i++)
        {
            for (int j = 1 ; j <= i ; j++)
            {
                cout << "*";
            }
            for (int k = 0 ; k < 2*n-2*i ; k++)
            {
                cout << " " ;
            }
            for (int l = 0 ; l < i ; l++)
            {
                cout << "*";
            }
            cout << "\n";
        }
        for (int i = 0; i < n-1 ; i++)
        {
            for (int j = 0 ; j < n-i-1 ; j++)
            {
                cout << "*";
            }
            for (int k = 0 ; k < 2*i+2 ; k++)
            {
                cout << " " ;
            }
            for (int l = 0 ; l < n-i-1 ; l++)
            {
                cout << "*";
            }
            cout << "\n";
        }
    }
    
};
class Solution21{
public:
    void pattern21(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++ )
            {
                if (i==0 || j==0 || i == n-1 || j == n-1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
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
    Solution11 sol1;
    cout << "The pattern is:" << "\n";
    sol1.pattern11(num) ;
    return 0;
}