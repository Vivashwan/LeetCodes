class CustomStack {
private:
    stack<int> st;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(st.size()<maxSize)
        {
            st.push(x);
        }
    }
    
    int pop() {
        if(!st.empty())
        {
            int val = st.top();
            st.pop();
            return val;
        }
        return -1;
    }
    
    void increment(int k, int value) {
        stack<int>tmp;

        while(!st.empty())
        {
            tmp.push(st.top());
            st.pop();
        }

        while(!tmp.empty())
        {
            if(k>0)
            {
                st.push(tmp.top()+value);
                tmp.pop();
                k--;
            }
            else
            {
                st.push(tmp.top());
                tmp.pop();
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */