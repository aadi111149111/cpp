#include <iostream>

class DoublyNode {
public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyCircularLinkedList {
private:
    DoublyNode* head;

public:
    DoublyCircularLinkedList() {
        head = nullptr;
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
void DoublyCircularLinkedList::insertBeginning(int val) {
    DoublyNode* newNode = new DoublyNode(val);
    if (head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    DoublyNode* tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
    head = newNode;
}

bool DoublyCircularLinkedList::insertAtPosition(int index, int val) {
    if (index < 0) return false;
    if (index == 0) {
        insertBeginning(val);
        return true;
    }
    if (head == nullptr) return false;

    DoublyNode* curr = head;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
        if (curr == head) return false;
    }

    DoublyNode* newNode = new DoublyNode(val);
    DoublyNode* succ = curr->next;

    newNode->next = succ;
    newNode->prev = curr;
    curr->next = newNode;
    succ->prev = newNode;
    return true;
}

void DoublyCircularLinkedList::insertEnd(int val) {
    DoublyNode* newNode = new DoublyNode(val);
    if (head == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    DoublyNode* tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
    head->prev = newNode;
}
bool DoublyCircularLinkedList::deleteBeginning() {
    if (head == nullptr) return false;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return true;
    }
    DoublyNode* tail = head->prev;
    DoublyNode* temp = head;

    head = head->next;
    head->prev = tail;
    tail->next = head;

    delete temp;
    return true;
}

bool DoublyCircularLinkedList::deleteAtPosition(int index) {
    if (head == nullptr || index < 0) return false;
    if (index == 0) return deleteBeginning();

    DoublyNode* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
        if (curr == head) return false;
    }

    DoublyNode* pred = curr->prev;
    DoublyNode* succ = curr->next;

    pred->next = succ;
    succ->prev = pred;

    delete curr;
    return true;
}

bool DoublyCircularLinkedList::deleteEnd() {
    if (head == nullptr) return false;
    if (head->next == head) {
        delete head;
        head = nullptr;
        return true;
    }
    DoublyNode* tail = head->prev;
    DoublyNode* newTail = tail->prev;

    newTail->next = head;
    head->prev = newTail;

    delete tail;
    return true;
}
void DoublyCircularLinkedList::displayForward() {
    if (head == nullptr) {
        std::cout << "DCLL Forward: Empty\n";
        return;
    }
    std::cout << "DCLL Forward: ";
    DoublyNode* curr = head;
    do {
        std::cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    std::cout << "\n";
}

void DoublyCircularLinkedList::displayBackward() {
    if (head == nullptr) {
        std::cout << "DCLL Backward: Empty\n";
        return;
    }
    std::cout << "DCLL Backward: ";
    DoublyNode* curr = head->prev;
    DoublyNode* tail = curr;
    do {
        std::cout << curr->data << " ";
        curr = curr->prev;
    } while (curr != tail);
    std::cout << "\n";
}
int main() {

    // Doubly Circular Linked List Verification
    DoublyCircularLinkedList dcll;
    dcll.insertEnd(100);
    dcll.insertEnd(300);
    dcll.insertBeginning(50);
    dcll.insertAtPosition(2, 200); // 50 <-> 100 <-> 200 <-> 300 <-> (50)
    dcll.displayForward();
    dcll.displayBackward();

    dcll.deleteBeginning();
    dcll.deleteAtPosition(1);
    dcll.deleteEnd();
    dcll.displayForward();

    return 0;
}