#include <iostream>
using namespace std;

// The blueprint for single node
class Node
{
public:
    int data;   // The Value inside the node
    Node* next;  // The address pointing to next node in memory

    // Constructor to set up the initial values instantly after object creation
    Node(int value)
    {
        data = value;
        next = nullptr;  // By default, it doesn't connect to any other node
    }
};

// The Blueprint for the list manager
class Linkedlist
{

private:
    Node* head;  // The pointer tracking the very first node

public:
    // Constructor to initialize an empty list
    Linkedlist()
    {
        head = nullptr; // Starts completely empty
    }
    void append(int value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp -> next; // Keep jumping to the next
        }
        temp->next = newNode; // Attach the new node to the end
    }

    void display()
    {
        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

int main()
{
    Node 
}