#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
class Selection_Sort
{
public:
    void sort(int *arr, int n )
    {        
        cout << "After selective sorting: [ ";
        for (int i = 0; i<=n-2; i++ )
        {
            int min = i;
            for(int j = i; j <=n-1; j++)
            {
                if (arr[j] < arr[min] )
                {
                    min = j;
                }
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
        for ( int i= 0;i<n; i++ )
        {
           cout << arr[i];
           if (i != n-1)
                cout << ", ";
           else
            cout << " ";
        }
        cout << "]\n";

    }
};
class Bubble_Sort
{
    
};
class Merge_Sort
{
public:
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid+1;
        while(left <= mid && right <= high)
        {
            if(arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        for(int i = low; i<= high; i++)
            arr[i] = temp[i - low];
    }
    void merge_sort( vector<int> &arr, int low, int high )
    {
        if (low >= high)
            return;
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
};
class Quick_Sort
{
public:
    void quick_sort( vector<int> arr, int low, int high)
    {
        if(low < high)
        {
            int pivot_index = partition(arr, low, high);
            quick_sort(arr, low, pivot_index-1);
            quick_sort(arr, pivot_index+1, high);
        }
    }
    int partition( vector<int> arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;
        while(i<j)
        {
            while(arr[i] <= arr[pivot] && i <= high)
            {
                i++;
            }
            while(arr[j] >= arr[pivot] && j >= low )
            {
                j--;
            }
            if(i<j)
            {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        return j;
    }
};



int main()
{
    int n;
    cout << "Enter the size of the array: " ;
    cin >> n;
    
    vector<int> array(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    cout << "The array before sorting is: [ " ; 
    for ( int i= 0; i < n; i++ )
    {
        cout << array[i];
        if (i != n-1)
            cout << ", ";
        else
            cout << " ";
        }
        cout << "]" << "\n";

    Selection_Sort sel;
    sel.sort(array.data(), n);
    Bubble_Sort bub;
    bub;

    int init = 0;
    int final = n-1;
    Merge_Sort merge;
    merge.merge_sort(array, init, final);
    cout << "After merge sorting: [ ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
        if (i != n - 1)
            cout << ", ";
        else
            cout << " ";
    }
    cout << "]\n";
    
    Quick_Sort quick;
    quick.quick_sort(array, init, final);
    cout << "After quick sorting: [ ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
        if (i != n - 1)
            cout << ", ";
        else
            cout << " ";
    }
    cout << "]\n";
    return 0;
}
