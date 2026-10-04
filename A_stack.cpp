#include <iostream>

class ArrayStack {
private:
    int arr[100];
    int topIndex;
    int capacity;

public:
    ArrayStack() {
        capacity = 100;
        topIndex = -1;
    }

    bool push(int val);
    bool pop(int& outVal);
    bool peek(int& outVal);
    bool isEmpty();
    bool isFull();
    void display();
};
bool ArrayStack::push(int val) {
    if (topIndex >= capacity - 1) {
        std::cout << "Stack Overflow\n";
        return false;
    }
    topIndex++;
    arr[topIndex] = val;
    return true;
}

bool ArrayStack::pop(int& outVal) {
    if (topIndex < 0) {
        std::cout << "Stack Underflow\n";
        return false;
    }
    outVal = arr[topIndex];
    topIndex--;
    return true;
}

bool ArrayStack::peek(int& outVal) {
    if (topIndex < 0) {
        std::cout << "Stack Underflow\n";
        return false;
    }
    outVal = arr[topIndex];
    return true;
}

bool ArrayStack::isEmpty() {
    return (topIndex == -1);
}

bool ArrayStack::isFull() {
    return (topIndex == capacity - 1);
}

void ArrayStack::display() {
    if (topIndex < 0) {
        std::cout << "ArrayStack: Empty\n";
        return;
    }
    std::cout << "ArrayStack (Top to Bottom): ";
    for (int i = topIndex; i >= 0; i--) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
int main() {
    int extracted = 0;

    // Array-Based Stack Testing
    ArrayStack aStack;
    aStack.push(10);
    aStack.push(20);
    aStack.push(30);
    aStack.display();

    if (aStack.peek(extracted)) {
        std::cout << "ArrayStack Peek: " << extracted << "\n";
    }

    aStack.pop(extracted);
    std::cout << "ArrayStack Popped: " << extracted << "\n";
    aStack.display();
    return 0;
}