class MyCircularQueue {
private:
    stack<int>primary, temp;
    int maxSize;
public:
    MyCircularQueue(int k) {
        maxSize=k;
    }
    
    bool enQueue(int value) {
        if(primary.size()==maxSize)
        {
            return false;
        }

        primary.push(value);

        return true;
    }
    
    bool deQueue() {
        if(primary.empty())
        {
            return false;
        }

        while(primary.size()>1)
        {
            temp.push(primary.top());
            primary.pop();
        }

        primary.pop();

        while(!temp.empty())
        {
            primary.push(temp.top());
            temp.pop();
        }

        return true;
    }
    
    int Front() {
        if(primary.empty())
        {
            return -1;
        }

        while(primary.size()>1)
        {
            temp.push(primary.top());
            primary.pop();
        }

        int val=primary.top();

        while(!temp.empty())
        {
            primary.push(temp.top());
            temp.pop();
        }

        return val;
    }
    
    int Rear() {
        if(primary.empty())
        {
            return -1;
        }

        return primary.top();
    }
    
    bool isEmpty() {
        return primary.empty();
    }
    
    bool isFull() {
        return primary.size()==maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */