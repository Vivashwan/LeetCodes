class Node{
public:
    Node* next, *prev;
    string str;

    Node(string &url)
    {
        this->str=url;
        next=nullptr, prev=nullptr;
    }
};

class BrowserHistory {
private:
    Node* curr=nullptr;
public:
    BrowserHistory(string homepage) {
        curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node* temp = new Node(url);

        curr->next = temp;
        temp->prev = curr;

        curr = curr->next; 
    }
    
    string back(int steps) {
        while(curr->prev && steps)
        {
            steps--;
            curr=curr->prev;
        }

        return curr->str;
    }
    
    string forward(int steps) {
        while(curr->next && steps)
        {
            steps--;
            curr=curr->next;
        }

        return curr->str;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */