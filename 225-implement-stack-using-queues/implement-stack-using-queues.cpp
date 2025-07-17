class MyStack {
public:
    queue<int> q1, q2;

    int currSize = 0;

    MyStack() {
        
    }
    
    void push(int x) {
        currSize++;
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q = q2;
        q2 = q1;
        q1 = q;
    }
    
    int pop() {
        if (q1.empty())
        {
            return -1;
        }
        
        currSize--;
        int temp =  q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        if (q1.empty())
        {
            return -1;
        }
        return q1.front();
    }
    
    bool empty() {
        if(currSize==0)
        {
            return true;
        }
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */