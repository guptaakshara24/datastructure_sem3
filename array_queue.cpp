#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int *arr;
    int capacity;
    int front, rear;
    int count;

public:
    ArrayQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isempty() {
        if (front == -1)
            return true;
        else
            return false;
    }

    bool isfull() {
        if (rear == capacity - 1)
            return true;
        else
            return false;
    }

    void enqueue(int x) {
        if (isfull()) {
            cout << "It's an overflow condition!!!" << endl;
            return;
        }

        if (isempty()) {
            front = 0;
        }

        rear += 1;
        arr[rear] = x;
        count++;

        cout << "Inserted " << x << " into the array." << endl;
    }

    void dequeue() {
        if (isempty()) {
            cout << "It's an underflow condition!!" << endl;
            return;
        }

        int temp = arr[front];
        front += 1;
        count--;

        if (front > rear) {
            front = -1;
            rear = -1;
        }

        cout << "Deleted " << temp << " from the array." << endl;
    }

    int size() {
        return count;
    }

    ~ArrayQueue() {
        delete[] arr;
    }
};

int main() {
    ArrayQueue q(3);

    q.enqueue(10);
    q.enqueue(100);
    q.enqueue(200);

    cout << "Size of the array is " << q.size() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}