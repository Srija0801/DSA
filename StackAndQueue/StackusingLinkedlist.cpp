class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedListStack {
private:
    Node* topNode;

public:
    LinkedListStack() {
        topNode = NULL;
    }

    void push(int x) {

        Node* newNode = new Node(x);

        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {

        if (isEmpty())
            return -1;

        int val = topNode->data;

        Node* temp = topNode;
        topNode = topNode->next;

        delete temp;

        return val;
    }

    int top() {

        if (isEmpty())
            return -1;

        return topNode->data;
    }

    bool isEmpty() {

        return topNode == NULL;
    }
};