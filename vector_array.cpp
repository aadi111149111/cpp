#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    arr.push_back(10);
    arr.insert(arr.begin()+ 4, 5);
    for(int i = 0; i < arr.size() ; i++)
    {
        cout << arr[i] << " ";
    }
    arr.pop_back();
    arr.erase(arr.begin());
    arr.erase(arr.begin()+4);
    cout << "\n";
    for(int i = 0; i < arr.size() ; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}