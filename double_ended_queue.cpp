#include <iostream>
using namespace std;

class ArrayDequeue {
private:
    int *arr;
    int capacity;
    int r, f, count;

public:
    ArrayDequeue(int size) {
        capacity = size;
        arr = new int[capacity];
        f = 0;
        r = -1;
        count = 0;
    }

    bool isfull() {
        if (count == capacity)
            return true;
        else
            return false;
    }

    bool isempty() {
        if (count == 0)
            return true;
        else
            return false;
    }

    void enqueueRear(int x) {
        if (isfull()) {
            cout << "Overflow!!" << endl;
            return;
        }

        r = (r + 1) % capacity;
        arr[r] = x;
        count++;

        cout << "Inserted " << x << " from rear." << endl;
    }

    void enqueueFront(int x) {
        if (isfull()) {
            cout << "Overflow!!" << endl;
            return;
        }

        if (isempty()) {
            f = 0;
            r = 0;
        } else {
            f = ((f - 1) + capacity) % capacity;
        }

        arr[f] = x;
        count++;

        cout << "Inserted " << x << " from front." << endl;
    }

    void dequeueFront() {
        if (isempty()) {
            cout << "Underflow!!" << endl;
            return;
        }

        int val = arr[f];
        f = (f + 1) % capacity;
        count--;

        if (count == 0) {
            f = 0;
            r = -1;
        }

        cout << "Deleted " << val << " from front." << endl;
    }

    void dequeueRear() {
        if (isempty()) {
            cout << "Underflow!!" << endl;
            return;
        }

        int val = arr[r];
        r = ((r - 1) + capacity) % capacity;
        count--;

        if (count == 0) {
            f = 0;
            r = -1;
        }

        cout << "Deleted " << val << " from rear." << endl;
    }

    void display() {
        if (isempty()) {
            cout << "Double ended queue is empty." << endl;
            return;
        }

        cout << "Double ended queue: ";

        int i = f;

        for (int j = 0; j < count; j++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }

        cout << endl;
    }

    int size() {
        return count;
    }

    ~ArrayDequeue() {
        delete[] arr;
    }
};

int main() {
    ArrayDequeue dq(5);

    dq.enqueueRear(10);
    dq.enqueueRear(20);
    dq.enqueueFront(5);

    dq.display();

    dq.dequeueFront();
    dq.dequeueRear();

    dq.display();

    cout << "Size: " << dq.size() << endl;

    return 0;
}