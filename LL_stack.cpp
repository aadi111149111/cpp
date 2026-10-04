#include<iostream>

class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedListStack {
private:
    StackNode* topNode;

public:
    LinkedListStack() {
        topNode = nullptr;
    }

    bool push(int val);
    bool pop(int& outVal);
    bool peek(int& outVal);
    bool isEmpty();
    void display();
};

bool LinkedListStack::push(int val) {
    StackNode* newNode = new StackNode(val);
    newNode->next = topNode;
    topNode = newNode;
    return true;
}

bool LinkedListStack::pop(int& outVal) {
    if (topNode == nullptr) {
        std::cout << "Stack Underflow\n";
        return false;
    }
    StackNode* temp = topNode;
    outVal = temp->data;
    topNode = topNode->next;
    delete temp;
    return true;
}

bool LinkedListStack::peek(int& outVal) {
    if (topNode == nullptr) {
        std::cout << "Stack Underflow\n";
        return false;
    }
    outVal = topNode->data;
    return true;
}

bool LinkedListStack::isEmpty() {
    return (topNode == nullptr);
}
void LinkedListStack::display() {
    if (topNode == nullptr) {
        std::cout << "LinkedListStack: Empty\n";
        return;
    }
    std::cout << "LinkedListStack (Top to Bottom): ";
    StackNode* curr = topNode;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}
int main() {
    int extracted = 0;
    // Linked List-Based Stack Testing
    LinkedListStack lStack;
    lStack.push(100);
    lStack.push(200);
    lStack.push(300);
    lStack.display();

    if (lStack.peek(extracted)) {
        std::cout << "LinkedListStack Peek: " << extracted << "\n";
    }

    lStack.pop(extracted);
    std::cout << "LinkedListStack Popped: " << extracted << "\n";
    lStack.display();

    return 0;
}