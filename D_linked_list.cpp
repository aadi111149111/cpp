#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertBeginning(int val);
    bool insertAtPosition(int index, int val);
    void insertEnd(int val);
    bool deleteBeginning();
    bool deleteAtPosition(int index);
    bool deleteEnd();
    void displayForward();
    void displayBackward();
};

void DoublyLinkedList::insertBeginning(int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

bool DoublyLinkedList::insertAtPosition(int index, int val) {
    if (index < 0) {
        std::cout << "Invalid index\n";
        return false;
    }

    if (index == 0) {
        insertBeginning(val);
        return true;
    }

    Node* curr = head;
    for (int i = 0; i < index - 1; i++) {
        if (curr == nullptr) {
            std::cout << "Index out of bounds\n";
            return false;
        }
        curr = curr->next;
    }

    if (curr == nullptr) {
        std::cout << "Index out of bounds\n";
        return false;
    }

    if (curr->next == nullptr) {
        insertEnd(val);
        return true;
    }

    Node* newNode = new Node(val);
    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next->prev = newNode;
    curr->next = newNode;
    return true;
}

void DoublyLinkedList::insertEnd(int val) {
    Node* newNode = new Node(val);

    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

bool DoublyLinkedList::deleteBeginning() {
    if (head == nullptr) {
        std::cout << "List is empty\n";
        return false;
    }

    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
    return true;
}

bool DoublyLinkedList::deleteAtPosition(int index) {
    if (head == nullptr || index < 0) {
        std::cout << "Invalid deletion request\n";
        return false;
    }

    if (index == 0) {
        return deleteBeginning();
    }

    Node* curr = head;
    for (int i = 0; i < index; i++) {
        if (curr == nullptr) {
            std::cout << "Index out of bounds\n";
            return false;
        }
        curr = curr->next;
    }

    if (curr == nullptr) {
        std::cout << "Index out of bounds\n";
        return false;
    }

    if (curr == tail) {
        return deleteEnd();
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    delete curr;
    return true;
}

bool DoublyLinkedList::deleteEnd() {
    if (tail == nullptr) {
        std::cout << "List is empty\n";
        return false;
    }

    Node* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete temp;
    return true;
}

void DoublyLinkedList::displayForward() {
    if (head == nullptr) {
        std::cout << "List is empty\n";
        return;
    }

    std::cout << "Forward: ";
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}

void DoublyLinkedList::displayBackward() {
    if (tail == nullptr) {
        std::cout << "List is empty\n";
        return;
    }

    std::cout << "Backward: ";
    Node* curr = tail;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->prev;
    }
    std::cout << "\n";
}

int main() {
    DoublyLinkedList dll;

    // 1. Insertion Operations
    dll.insertEnd(10);
    dll.insertEnd(30);
    dll.insertBeginning(5);
    dll.insertAtPosition(2, 20); // List: 5 <-> 10 <-> 20 <-> 30
    dll.displayForward();
    dll.displayBackward();

    // 2. Deletion Operations
    dll.deleteBeginning();       // Removes 5
    dll.displayForward();

    dll.deleteAtPosition(1);     // Removes 20
    dll.displayForward();

    dll.deleteEnd();            // Removes 30
    dll.displayForward();

    return 0;
}