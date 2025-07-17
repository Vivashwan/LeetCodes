class MyCircularDeque {
public:
    stack<int>data;
    int maxSize;

    MyCircularDeque(int k) {
        maxSize=k;
    }

    bool insertFront(int value) {
        if(data.size()<maxSize) 
        {
            data.push(value);
            return true;
        }

        return false;
    }

    bool insertLast(int value) {

        if(data.size()<maxSize)
        {
            stack<int>temp;
            while(!data.empty())
            {
                temp.push(data.top());
                data.pop();
            }

            data.push(value);

            while (!temp.empty())
            {
                data.push(temp.top());
                temp.pop();
            }

            return true;
        }

        return false;
    }

    bool deleteFront() {
        if(!data.empty())
        {
            data.pop();
            return true;
        }
        return false;
    }

    bool deleteLast() {
        if(!data.empty()) 
        {
            stack<int>temp;

            while(data.size()>1)
            {
                temp.push(data.top());
                data.pop();
            }

            data.pop();

            while(!temp.empty())
            {
                data.push(temp.top());
                temp.pop();
            }
            return true;
        }

        return false;
    }

    int getFront() {
        if(!data.empty())
        {
            return data.top();
        }

        return -1;
    }

    int getRear() {
        if(!data.empty())
        {
            stack<int>temp=data;

            while(temp.size()>1)
            {
                temp.pop();
            }

            return temp.top();
        }

        return -1;
    }

    bool isEmpty() {
        return data.empty();
    }

    bool isFull() {
        return data.size()==maxSize;
    }
};