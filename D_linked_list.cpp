#include <iostream>
using namespace std;

class DLLNode {
public:
    int data;
    DLLNode* prev;
    DLLNode* next;

    DLLNode(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Convert Array to Doubly Linked List
DLLNode* arrayToDLL(int arr[], int size) {
    if (size == 0) return nullptr;
    
    DLLNode* head = new DLLNode(arr[0]);
    DLLNode* temp = head;
    
    for (int i = 1; i < size; i++) {
        DLLNode* newNode = new DLLNode(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
    return head;
}

void insertAtHead(DLLNode*& head, int val) {
    DLLNode* newNode = new DLLNode(val);
    if (head != nullptr) {
        head->prev = newNode;
        newNode->next = head;
    }
    head = newNode;
}

void insertAtLast(DLLNode*& head, int val) {
    if (head == nullptr) {
        insertAtHead(head, val);
        return;
    }
    DLLNode* newNode = new DLLNode(val);
    DLLNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(DLLNode*& head, int val, int pos) {
    if (pos <= 1) {
        insertAtHead(head, val);
        return;
    }
    DLLNode* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        insertAtLast(head, val);
        return;
    }
    DLLNode* newNode = new DLLNode(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteAtHead(DLLNode*& head) {
    if (head == nullptr) return;
    DLLNode* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void deleteAtLast(DLLNode*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    DLLNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

void deleteAtPosition(DLLNode*& head, int pos) {
    if (head == nullptr) return;
    if (pos <= 1) {
        deleteAtHead(head);
        return;
    }
    DLLNode* temp = head;
    for (int i = 1; temp != nullptr && i < pos; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) return;
    
    temp->prev->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

int search(DLLNode* head, int val) {
    DLLNode* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == val) return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

void traverseAndPrint(DLLNode* head) {
    DLLNode* temp = head;
    cout << "NULL <- ";
    while (temp != nullptr) {
        cout << "[" << temp->data << "] <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    cout << "=== Doubly Linked List Operations ===" << endl;
    
    // 1. Convert Array to DLL
    int arr[] = {10, 20, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    DLLNode* head = arrayToDLL(arr, size);
    
    cout << "Initial List from Array:" << endl;
    traverseAndPrint(head); 
    // Output: NULL <- [10] <-> [20] <-> [30] <-> [40] <-> NULL

    // 2. Test Insertions
    cout << "\nInserting 5 at Head, 50 at Last, and 25 at Position 4:" << endl;
    insertAtHead(head, 5);
    insertAtLast(head, 50);
    insertAtPosition(head, 25, 4);
    traverseAndPrint(head);
    // Output: NULL <- [5] <-> [10] <-> [20] <-> [25] <-> [30] <-> [40] <-> [50] <-> NULL

    // 3. Test Deletions
    cout << "\nDeleting at Head, Last, and Position 3:" << endl;
    deleteAtHead(head);
    deleteAtLast(head);
    deleteAtPosition(head, 3); // Deletes the node at position 3 (which is 25)
    traverseAndPrint(head);
    // Output: NULL <- [10] <-> [20] <-> [30] <-> [40] <-> NULL

    // 4. Test Search
    cout << "\nSearching for value 30:" << endl;
    int pos = search(head, 30);
    if (pos != -1) {
        cout << "Found 30 at position: " << pos << endl;
    } else {
        cout << "Value 30 not found." << endl;
    }

    return 0;
}