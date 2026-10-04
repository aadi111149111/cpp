#include <iostream>
class SinglyNode {
public:
    int data;
    SinglyNode* next;

    SinglyNode(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyCircularLinkedList {
private:
    SinglyNode* head;
    SinglyNode* tail;

public:
    SinglyCircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertBeginning(int val);
    bool insertAtPosition(int index, int val);
    void insertEnd(int val);
    bool deleteBeginning();
    bool deleteAtPosition(int index);
    bool deleteEnd();
    void display();
};
void SinglyCircularLinkedList::insertBeginning(int val) {
    SinglyNode* newNode = new SinglyNode(val);
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

bool SinglyCircularLinkedList::insertAtPosition(int index, int val) {
    if (index < 0) return false;
    if (index == 0) {
        insertBeginning(val);
        return true;
    }
    if (head == nullptr) return false;

    SinglyNode* curr = head;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
        if (curr == head) return false;
    }

    if (curr == tail) {
        insertEnd(val);
        return true;
    }

    SinglyNode* newNode = new SinglyNode(val);
    newNode->next = curr->next;
    curr->next = newNode;
    return true;
}

void SinglyCircularLinkedList::insertEnd(int val) {
    SinglyNode* newNode = new SinglyNode(val);
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}
bool SinglyCircularLinkedList::deleteBeginning() {
    if (head == nullptr) return false;
    SinglyNode* temp = head;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        tail->next = head;
    }
    delete temp;
    return true;
}

bool SinglyCircularLinkedList::deleteAtPosition(int index) {
    if (head == nullptr || index < 0) return false;
    if (index == 0) return deleteBeginning();

    SinglyNode* curr = head;
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
        if (curr->next == head) return false;
    }

    SinglyNode* target = curr->next;
    if (target == head) return false;
    if (target == tail) return deleteEnd();

    curr->next = target->next;
    delete target;
    return true;
}

bool SinglyCircularLinkedList::deleteEnd() {
    if (head == nullptr) return false;
    SinglyNode* temp = tail;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        SinglyNode* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }
        curr->next = head;
        tail = curr;
    }
    delete temp;
    return true;
}

void SinglyCircularLinkedList::display() {
    if (head == nullptr) {
        std::cout << "SCLL: Empty\n";
        return;
    }
    std::cout << "SCLL: ";
    SinglyNode* curr = head;
    do {
        std::cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    std::cout << "(returns to " << head->data << ")\n";
}
int main() {
    // Singly Circular Linked List Verification
    SinglyCircularLinkedList scll;
    scll.insertEnd(10);
    scll.insertEnd(30);
    scll.insertBeginning(5);
    scll.insertAtPosition(2, 20); // 5 -> 10 -> 20 -> 30 -> (5)
    scll.display();

    scll.deleteBeginning();
    scll.deleteAtPosition(1);
    scll.deleteEnd();
    scll.display();

    return 0;
}