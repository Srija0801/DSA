class ArrayStack {
private:
    vector<int> arr;
    int topIndex;

public:
    ArrayStack() {
        topIndex = -1;
    }

    void push(int x) {
        arr.push_back(x);
        topIndex++;
    }

    int pop() {

        if (isEmpty())
            return -1;

        int val = arr[topIndex];
        arr.pop_back();
        topIndex--;

        return val;
    }

    int top() {

        if (isEmpty())
            return -1;

        return arr[topIndex];
    }

    bool isEmpty() {

        return topIndex == -1;
    }
};