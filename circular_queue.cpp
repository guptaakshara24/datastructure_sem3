#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int capacity;
    int f, r, count;

public:
    CircularQueue(int size) {
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

    void enqueue(int x) {
        if (isfull()) {
            cout << "This is an overflow condition!!" << endl;
            return;
        }

        r = (r + 1) % capacity;
        arr[r] = x;
        count++;

        cout << "Inserted " << x << " in the circular queue." << endl;
    }

    void dequeue() {
        if (isempty()) {
            cout << "This is an underflow condition!!" << endl;
            return;
        }

        int temp = arr[f];
        f = (f + 1) % capacity;
        count--;

        if (count == 0) {
            f = 0;
            r = -1;
        }

        cout << "Deleted " << temp << " from the circular queue." << endl;
    }

    int size() {
        return count;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue cq(3);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);

    cout << "Size : " << cq.size() << endl;

    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();

    return 0;
}