class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedListQueue {
private:
    Node* frontNode;
    Node* rearNode;

public:
    LinkedListQueue() {
        frontNode = NULL;
        rearNode = NULL;
    }

    void push(int x) {

        Node* newNode = new Node(x);

        if (isEmpty()) {
            frontNode = rearNode = newNode;
            return;
        }

        rearNode->next = newNode;
        rearNode = newNode;
    }

    int pop() {

        if (isEmpty())
            return -1;

        int val = frontNode->data;

        Node* temp = frontNode;
        frontNode = frontNode->next;

        if (frontNode == NULL)
            rearNode = NULL;

        delete temp;

        return val;
    }

    int peek() {

        if (isEmpty())
            return -1;

        return frontNode->data;
    }

    bool isEmpty() {

        return frontNode == NULL;
    }
};