#include <iostream>
using namespace std;

class arrayinit
{
private:
    int arr[100];
    int capacity;
    int size;

public:
    arrayinit()
    {
    capacity = 100;
    size = 0;
    }

    bool insert_at_beginning(int value)
    {
        if(size == capacity)
        {
            cout << "Array is full\n";
            return false;
        }
        else if (size > capacity)
        {
            cout << "Can't add into already occupied array\n";
            return false;
        }
        else
        {
            for(int i = size; i > 0; i--)
            {
                arr[i] = arr[i-1];
            }
            arr[0] = value;
            size++;
            return true;
        }
    }
    bool insert_at_end(int value)
    {
        if(size == capacity)
        {
            cout << "Array is full\n";
            return false;
        }
        else if (size > capacity)
        {
            cout << "Can't add into already occupied array\n";
            return false;
        }
        else
        {
            arr[size] = value;
            size++;
            return true; 
        }
    }
    bool insert_at_position(int index, int value)
    {
        if(size == capacity)
        {
            cout << "Array is full\n";
            return false;
        }
        else if (size > capacity)
        {
            cout << "Can't add into already occupied array\n";
            return false;
        }
        else if (index < 0 || index > size) 
        {
            cout << "Invalid index position\n";
            return false;   
        }
        else
        {
            for(int i = size; i> index; i--)
            {
                arr[i] = arr[i-1];
            }
            arr[index] = value;
            size++;
            return true;
        }
    }
    bool delete_at_beginning()
    {
        if (size <= 0 )
        {
            cout << "Array is empty\n";
            return false;
        }
        else
        {
            for(int i = 0; i < size-1; i++)
            {
                arr[i] = arr[i+1];
            }
            size--;
            return true;
        }
    }
    bool delete_at_position_k(int index)
    {
        if (size <= 0 )
        {
            cout << "Array is empty\n";
            return false;
        }
        else if(index < 0 || index >= size)
        {
            cout << " Array out of bounds\n";
            return false;
        }
        else
        {
            for(int i = index; i < size-1; i++)
            {
                arr[i] = arr[i+1];
            }
            size--;
            return true;
        }
    }
    bool delete_at_end()
    {
        if (size <= 0 )
        {
            cout << "Array is empty\n";
            return false;
        }
        else
        {
            size--;
            return true;
        }
        
    }
    bool display()
    {
        if(size == 0)
        {
            cout << "Array is empty\n";
            return false;
        }
        else
        {
            for(int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout <<"\n";
        }
        return true;
    }
};


int main()
{
    arrayinit a1;
    a1.insert_at_beginning(10);
    a1.display();
    a1.insert_at_beginning(20);
    a1.display();
    a1.insert_at_beginning(30);
    a1.display();
    a1.insert_at_beginning(40);
    a1.display();
    a1.insert_at_beginning(50);
    a1.display();
    a1.insert_at_beginning(60);
    a1.display();
    a1.insert_at_position(3, 40);
    a1.display();
    a1.insert_at_end(10);
    a1.display();
    a1.insert_at_end(20);
    a1.display();
    a1.insert_at_end(30);
    a1.display();
    a1.insert_at_end(40);
    a1.display();
    a1.insert_at_end(50);
    a1.display();
    a1.insert_at_end(60);
    a1.display();
    a1.delete_at_beginning();
    a1.display();
    a1.delete_at_beginning();
    a1.display();
    a1.delete_at_position_k(3);
    a1.display();
    a1.delete_at_end();
    a1.display();
    return 0;
}