#include <iostream>
#include <vector>
using namespace std;

void pairexp()
{
    pair<int,float> p = {1,2.56};
    cout << p.first << " " << p.second << "\n";
    pair<int, pair<int, int>> q = {1, {2,3}};
    cout << p.first << " " << q.second.first << " "<<q.second.second << "\n";
    pair<int, int> arr[5] = {{1,2}, {2,3}, {3,4}};
    cout << arr[1].first <<" "<< arr[2].second << "\n" ;
}

void vectorexplain()
{
    vector <int> v ;
    v.push_back(1);
    v.emplace_back(2);

    vector <pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);
    
    vector <int> v1(5,100);

    v1.push_back(1000);
    vector <int> v2(5);

    vector<int> v3(5,20);

    vector <int> v4(v1);

    vector <int> :: iterator it = v.begin();
    it++;
    cout << *(it) << " ";

    // it = it+2;
    // cout << *(it) << " ";

    //vector<int>:: iterator 
    it = v.end();

    vector<int>::reverse_iterator rit = v.rend();
    //vector<int>:: reverse_iterator 
    rit = v.rend();

    //vector<int>:: reverse_iterator
     rit = v.rbegin();

    cout<< v[0] << " " << v.at(1);
    cout << v.back() << " ";
    for(vector<int>::iterator it = v1.begin(); it!= v1.end(); it++)
    {
        cout << *(it) << " ";
    }
}
    


int main()
{
    pairexp();
    vectorexplain();
    return 0;
}