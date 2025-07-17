class MyQueue {
public:
    stack<int>main, helper;

    MyQueue() {}

    void push(int x) {
        while(!main.empty())
        {
            helper.push(main.top());
            main.pop();
        }

        main.push(x);

        while(!helper.empty())
        {
            main.push(helper.top());
            helper.pop();
        }
    }

    int pop() {
        if(main.empty())
        { 
            return -1;
        }

        int front=main.top();
        main.pop();
        return front;
    }

    int peek() {
        if(main.empty())
        { 
            return -1;
        }
        
        return main.top();
    }

    bool empty() {
        return main.empty();
    }
};
