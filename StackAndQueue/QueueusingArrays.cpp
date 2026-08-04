class ArrayQueue {
private:
    int arr[1000];
    int front;
    int rear;
    int size;

public:
    ArrayQueue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void push(int x) {

        if(size == 1000)
            return;      // Queue Full

        rear = (rear + 1) % 1000;
        arr[rear] = x;
        size++;
    }

    int pop() {

        if(isEmpty())
            return -1;

        int val = arr[front];
        front = (front + 1) % 1000;
        size--;

        return val;
    }

    int peek() {

        if(isEmpty())
            return -1;

        return arr[front];
    }

    bool isEmpty() {

        return size == 0;
    }
};