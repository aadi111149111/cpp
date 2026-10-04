#include <iostream>
using namespace std;
class SimpleArray {
private:
    int arr[100];
    int capacity;
    int size;

public:
    SimpleArray() {
        capacity = 100;
        size = 0;
    }

    bool insertBeginning(int value);
    bool insertAtPosition(int index, int value);
    bool insertEnd(int value);
    bool deleteBeginning();
    bool deleteAtPosition(int index);
    bool deleteEnd();
    void display();
};

bool SimpleArray::insertBeginning(int value) {
    if (size >= capacity) {
        cout << "Array is full\n";
        return false;
    }

    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = value;
    size++;
    return true;
}

bool SimpleArray::insertAtPosition(int index, int value) {
    if (size >= capacity) {
        cout << "Array is full\n";
        return false;
    }
    if (index < 0 || index > size) {
        cout << "Invalid index\n";
        return false;
    }

    for (int i = size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = value;
    size++;
    return true;
}

bool SimpleArray::insertEnd(int value) {
    if (size >= capacity) {
        cout << "Array is full\n";
        return false;
    }

    arr[size] = value;
    size++;
    return true;
}

bool SimpleArray::deleteBeginning() {
    if (size <= 0) {
cout << "Array is empty\n";
        return false;
    }

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    return true;
}

bool SimpleArray::deleteAtPosition(int index) {
    if (size <= 0) {
        std::cout << "Array is empty\n";
        return false;
    }
    if (index < 0 || index >= size) {
        std::cout << "Invalid index\n";
        return false;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    return true;
}

bool SimpleArray::deleteEnd() {
    if (size <= 0) {
        cout << "Array is empty\n";
        return false;
    }

    size--;
    return true;
}

void SimpleArray::display() {
    if (size == 0) {
        cout << "Array is empty\n";
        return;
    }

    cout << "Elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    SimpleArray a;

    // Insertion operations
    a.insertEnd(10);
    a.insertEnd(20);
    a.insertEnd(30);
    a.display();

    a.insertBeginning(5);
    a.display();

    a.insertAtPosition(2, 15);
    a.display();

    // Deletion operations
    a.deleteBeginning();
    a.display();

    a.deleteAtPosition(1);
    a.display();

    a.deleteEnd();
    a.display();

    return 0;
}