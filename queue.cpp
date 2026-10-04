#include <iostream>

class OrdinaryQueue {
private:
    int arr[5];
    int front;
    int rear;
    int capacity;

public:
    OrdinaryQueue() {
        capacity = 5;
        front = -1;
        rear = -1;
    }

    bool enqueue(int val);
    bool dequeue(int& outVal);
    bool isEmpty();
    bool isFull();
    void display();
};
bool OrdinaryQueue::isFull() {
    return rear == capacity - 1;
}

bool OrdinaryQueue::isEmpty() {
    return front == -1 || front > rear;
}

bool OrdinaryQueue::enqueue(int val) {
    if (isFull()) {
        std::cout << "OrdinaryQueue Overflow\n";
        return false;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    arr[rear] = val;
    return true;
}

bool OrdinaryQueue::dequeue(int& outVal) {
    if (isEmpty()) {
        std::cout << "OrdinaryQueue Underflow\n";
        return false;
    }

    outVal = arr[front];
    front++;

    if (front > rear) {
        front = -1;
        rear = -1;
    }

    return true;
}

void OrdinaryQueue::display() {
    if (isEmpty()) {
        std::cout << "OrdinaryQueue: Empty\n";
        return;
    }

    std::cout << "OrdinaryQueue: ";
    for (int i = front; i <= rear; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

class CircularQueue {
private:
    int arr[5];
    int front;
    int rear;
    int capacity;

public:
    CircularQueue() {
        capacity = 5;
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool enqueue(int val) {
        if (isFull()) {
            std::cout << "CircularQueue Overflow\n";
            return false;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = val;
        return true;
    }

    bool dequeue(int& outVal) {
        if (isEmpty()) {
            std::cout << "CircularQueue Underflow\n";
            return false;
        }

        outVal = arr[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        return true;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "CircularQueue: Empty\n";
            return;
        }

        std::cout << "CircularQueue: ";
        int i = front;
        while (true) {
            std::cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        std::cout << "\n";
    }
};
class Deque {
private:
    int arr[5];
    int front;
    int rear;
    int capacity;

public:
    Deque() {
        capacity = 5;
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    bool insertFront(int val) {
        if (isFull()) {
            std::cout << "Deque Overflow\n";
            return false;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front = front - 1;
        }

        arr[front] = val;
        return true;
    }

    bool insertRear(int val) {
        if (isFull()) {
            std::cout << "Deque Overflow\n";
            return false;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }

        arr[rear] = val;
        return true;
    }

    bool deleteFront(int& outVal) {
        if (isEmpty()) {
            std::cout << "Deque Underflow\n";
            return false;
        }

        outVal = arr[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front = front + 1;
        }

        return true;
    }

    bool deleteRear(int& outVal) {
        if (isEmpty()) {
            std::cout << "Deque Underflow\n";
            return false;
        }

        outVal = arr[rear];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear = rear - 1;
        }

        return true;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Deque: Empty\n";
            return;
        }

        std::cout << "Deque: ";
        int i = front;
        while (true) {
            std::cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        std::cout << "\n";
    }
};
class PriorityQueue {
private:
    int data[5];
    int priority[5];
    int size;
    int capacity;

public:
    PriorityQueue() {
        capacity = 5;
        size = 0;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool enqueue(int val, int p) {
        if (isFull()) {
            std::cout << "PriorityQueue Overflow\n";
            return false;
        }

        int i = size - 1;
        while (i >= 0 && priority[i] > p) {
            data[i + 1] = data[i];
            priority[i + 1] = priority[i];
            i--;
        }

        data[i + 1] = val;
        priority[i + 1] = p;
        size++;
        return true;
    }

    bool dequeue(int& outVal) {
        if (isEmpty()) {
            std::cout << "PriorityQueue Underflow\n";
            return false;
        }

        outVal = data[size - 1];
        size--;
        return true;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "PriorityQueue: Empty\n";
            return;
        }

        std::cout << "PriorityQueue: ";
        for (int i = size - 1; i >= 0; i--) {
            std::cout << "[" << data[i] << ", p=" << priority[i] << "] ";
        }
        std::cout << "\n";
    }
};
int main() {
    int extracted = 0;

    // 1. Ordinary Queue Verification (demonstrating false overflow)
    OrdinaryQueue oq;
    oq.enqueue(10);
    oq.enqueue(20);
    oq.enqueue(30);
    oq.display();
    oq.dequeue(extracted);
    std::cout << "OrdinaryQueue Dequeued: " << extracted << "\n";
    oq.display();

    // 2. Circular Queue Verification
    CircularQueue cq;
    cq.enqueue(100);
    cq.enqueue(200);
    cq.enqueue(300);
    cq.dequeue(extracted);
    cq.enqueue(400);
    cq.display();

    // 3. Deque Verification
    Deque dq;
    dq.insertRear(50);
    dq.insertFront(25);
    dq.insertRear(75);
    dq.display();
    dq.deleteFront(extracted);
    dq.display();

    // 4. Priority Queue Verification
    PriorityQueue pq;
    pq.enqueue(500, 1);
    pq.enqueue(900, 3); // Highest priority
    pq.enqueue(700, 2);
    pq.display();
    pq.dequeue(extracted);
    std::cout << "PriorityQueue Extracted: " << extracted << "\n";
    pq.display();

    return 0;
}