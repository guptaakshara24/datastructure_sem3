#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    int priority;
    Node *next;

    Node(int val, int p)
    {
        data = val;
        priority = p;
        next = NULL;
    }
};

class PriorityQueue
{
private:
    Node *front;

public:
    PriorityQueue()
    {
        front = NULL;
    }

    void enqueue(int val, int p)
    {
        Node *newNode = new Node(val, p);

        if(front == NULL || p > front->priority)
        {
            newNode->next = front;
            front = newNode;
            return;
        }

        Node *temp = front;

        while(temp->next != NULL && temp->next->priority >= p)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void dequeue()
    {
        if(front == NULL)
        {
            cout << "Empty" << endl;
            return;
        }

        Node *temp = front;
        cout << temp->data << endl;
        front = front->next;
        delete temp;
    }

    void peek()
    {
        if(front == NULL)
        {
            cout << "Empty" << endl;
            return;
        }

        cout << front->data << endl;
    }
};

int main()
{
    PriorityQueue pq;
    int q;

    cin >> q;

    for(int i = 0; i < q; i++)
    {
        string operation;
        cin >> operation;

        if(operation == "ENQUEUE")
        {
            int value, priority;
            cin >> value >> priority;
            pq.enqueue(value, priority);
        }
        else if(operation == "DEQUEUE")
        {
            pq.dequeue();
        }
        else if(operation == "PEEK")
        {
            pq.peek();
        }
    }

    return 0;
}