#include <iostream>
using namespace std;

struct Element {
    int data;
    int priority;
};

class PriorityQueue {
private:
    Element *arr;
    int capacity;
    int count;

public:
    PriorityQueue(int size) {
        capacity = size;
        arr = new Element[capacity];
        count = 0;
    }

    bool isempty() {
        if (count == 0)
            return true;
        else
            return false;
    }

    bool isfull() {
        if (count == capacity)
            return true;
        else
            return false;
    }

    void enqueue(int val, int p) {
        if (isfull()) {
            cout << "Overflow condition!!" << endl;
            return;
        }

        int i = count - 1;

        while (i >= 0 && arr[i].priority > p) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1].data = val;
        arr[i + 1].priority = p;

        cout << "The value inserted is " << val << endl;

        count++;
    }

    void dequeue() {
        if (isempty()) {
            cout << "Underflow condition!!" << endl;
            return;
        }

        int value = arr[count - 1].data;

        cout << "The value deleted is " << value << endl;

        count--;
    }

    int peek() {
        if (isempty()) {
            cout << "Priority queue is empty." << endl;
            return -1;
        }

        return arr[count - 1].data;
    }

    int size() {
        return count;
    }

    ~PriorityQueue() {
        delete[] arr;
    }
};

int main() {
    PriorityQueue pq(3);

    pq.enqueue(10, 9);
    pq.enqueue(20, 3);
    pq.enqueue(90, 5);

    cout << "The element at the top is " << pq.peek() << endl;
    cout << "Size : " << pq.size() << endl;

    pq.dequeue();
    pq.dequeue();
    pq.dequeue();

    return 0;
}