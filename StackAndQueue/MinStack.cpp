class MinStack {
    stack<pair<int,int>>st;
    int currentMin;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            currentMin=value;
            st.push({value,currentMin});
        }else{
            currentMin=min(value,currentMin);
            st.push({value,currentMin});
        }
    }
    
    void pop() {
       st.pop();
       if(!st.empty()){
          currentMin=st.top().second;
       } 
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */