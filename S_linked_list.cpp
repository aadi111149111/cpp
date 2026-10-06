#include <iostream>
#include <vector>

using namespace std;
class Node // Creating node here
{
public:
    int data;
    Node* next;
public:
    // Node(int data1, Node* next1) // To create a node with data and pointer to the next node
    // {
    //     data = data1;
    //     next = next1;
    // }
    Node(int data1) // To create a node with data and a null pointer for the next node
    {
        data = data1;
        next = nullptr;
    }
};
// To print all of the data elements inside the Linked List
void traverse(Node* head) // Done
{
    Node* temp = head;
    while(temp != nullptr)
    {

        cout << temp-> data << " ";
        temp = temp -> next;        
    }
    cout << endl;
}
// To convert an array into a Linked List 
Node* convertArr2LL(vector<int> &arr) //Done
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}
// To find the length of the Linked List
int lengthOfLL(Node* head) // Done
{
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr)
    {
        temp = temp -> next;
        cnt++;
    }
    return cnt;
}

// To search a value inside a Linked List
Node* checkIfPresent(Node* head, int val) // Done
{
    Node* temp = head;
    int count = 0;
    while(temp != nullptr)
    {
        count++;
        if(temp -> data == val)
            {
                cout << "Found value " << val << " at position: " << count << endl;
                return temp;
            }
        temp = temp -> next;
    }
    return 0 ;
}

// Deletion of elements
// 1. Deletion from head

Node* removesHead(Node* head)// Done
{
    Node* temp = head;
    if(head == NULL || head->next == nullptr) // Means if the Linked List is empty and next pointer to the head is also null, so that the whole LL doesn't becomeempty5 
    {
        return nullptr;
    }

    head = head-> next;
    delete temp;
    return head;
}
// 2. Deletion from tail

Node* removesTail(Node* head)//Done
{
    if(head == NULL || head-> next == NULL)
    {
        return nullptr;
    }
    Node* temp = head;
    while(temp-> next -> next != NULL)
    {
        temp = temp-> next;
    }
    delete(temp-> next);
    temp -> next = nullptr;
    return head; 
}

// 3. Deletion from Kth position

Node* Delete_at_Position_K(Node* head, int k)
{
    if (head == NULL || head -> next == NULL)
    {
        return nullptr;
    }
    else if (k == 1)
    {
        removesHead(head);
    }
    int count = 0; 
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev -> next = prev-> next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp-> next;
    }
    return head;
}
//  4. Deletion using value

Node* Deletion_by_value(Node* head, int element )
{
    if (head == NULL)
        return head;
    if (head-> data == element)
        {
            Node* temp = head;
            head = head-> next;
            delete temp;
            return head;
        }
    Node* temp = head;
    Node* previous = NULL;
    while(temp != NULL)
    {
        if (temp-> data == element)
        {
            previous-> next = previous-> next -> next;
            delete temp;
            break;
        }
        previous = temp;
        temp = temp-> next;
    }
    return head;
}

// Insertion of elements
// 1. Insertion at initial position
Node* insert_at_beginning(Node* head, int val)
{
    Node* newhead = new Node(val);
    newhead-> next = head;
    return newhead;
}
// 2. Insertion from final position
Node* insert_at_last(Node* head, int val)
{
    Node* new_tail = new Node(val);
    Node* temp = head;
    if (temp == nullptr)
    {
        head = new_tail;
        return head;
    }
    while(temp->next != nullptr)
    {
        temp = temp-> next;
    }
    temp-> next = new_tail;
    return head;
}
// 3. Insertion from kth position

Node* insertion_at_kth_position(Node* head, int k)
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
     Node* new_node = new Node(num);
        if (k == 1) {
        insert_at_beginning(head, num);
        }
        int count = 1;
        Node* temp = head;
        while (temp != nullptr && count < k - 1) {
            count++;
            temp = temp->next;
        }
        if (head == nullptr) return head;

        new_node->next = temp->next;
        temp->next = new_node;
        return head;
}

// 4. Insertion using value


int main()
{
    vector<int> arr = {1,2,3,4,5};
    // Node *y = new Node(arr[0]);
    // int new_val = 0;
    // Node *y = new Node(arr[0], nullptr);
    // cout << y.data << "\n";
    // cout << y.next;    
    // cout << y->data << "\n";
    // cout << y->next << "\n";
    Node* head = convertArr2LL(arr);
    cout << "\n";
    cout << lengthOfLL(head);
    cout << "\n";
    cout << checkIfPresent(head, 5) << endl;
    head = removesHead(head);
    // head = removesTail(head);
    //head = Delete_at_Position_K(head, 1);
    //head = Deletion_by_value(head, 4);
    //Node* new_head = insert_at_beginning(head, new_val);
    //Node* new_tail = insert_at_last(head, new_val);
    // int position;
    // cout << "Enter the position: ";
    // cin >> position;
    // Node* new_at_k = insertion_at_kth_position(head, position);
    traverse(head);
    return 0;
}
