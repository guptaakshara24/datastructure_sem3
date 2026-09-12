#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LinkedDequeue {
private:
    Node *front, *rear;
    int count;

public:
    LinkedDequeue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }

    bool isempty() {
        return front == nullptr;
    }

    void insertAtFront(int x) {
        Node *newNode = new Node(x);

        if (isempty()) {
            rear = front = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        cout << x << " is inserted at front." << endl;
        count++;
    }

    void insertAtRear(int x) {
        Node *newNode = new Node(x);

        if (isempty()) {
            rear = front = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }

        cout << x << " is inserted at rear." << endl;
        count++;
    }

    void deletionFront() {
        if (isempty()) {
            cout << "It's an underflow condition!" << endl;
            return;
        }

        Node *temp = front;
        int value = temp->data;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = temp->next;
            front->prev = nullptr;
        }

        delete temp;

        cout << value << " is deleted from front." << endl;
        count--;
    }

    void deletionRear() {
        if (isempty()) {
            cout << "It's an underflow condition!" << endl;
            return;
        }

        Node *temp = rear;
        int value = temp->data;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = temp->prev;
            rear->next = nullptr;
        }

        delete temp;

        cout << value << " is deleted from rear." << endl;
        count--;
    }

    int size() {
        return count;
    }

    void display() {
        if (isempty()) {
            cout << "Double ended queue is empty." << endl;
            return;
        }

        Node *temp = front;

        cout << "Double ended queue: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    LinkedDequeue dq;

    dq.insertAtFront(10);
    dq.insertAtFront(20);
    dq.insertAtRear(30);

    dq.display();

    cout << "Size : " << dq.size() << endl;

    dq.deletionFront();

    dq.insertAtFront(5);

    dq.deletionRear();

    dq.display();

    return 0;
}