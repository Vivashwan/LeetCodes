class LRUCache {
public:
    class Node{
    public:
        Node* next, *prev;
        int key, val;

        Node(int x, int y)
        {
            key=x, val=y;
        }
    };

    Node* head=new Node(-1, -1);
    Node* tail=new Node(-1, -1);

    int cap;
    unordered_map<int, Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void deleteNode(Node* curr)
    {
        Node* currPrev=curr->prev;
        Node* currNext=curr->next;

        curr->prev=nullptr;

        currPrev->next=currNext;
        currNext->prev=currPrev;
    }

    void addNode(Node* newNode)
    {
        Node* temp=head->next;
        head->next=newNode;
        newNode->next=temp;
        temp->prev=newNode;
        newNode->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            int val=mp[key]->val;

            deleteNode(mp[key]);
            addNode(mp[key]);
            mp.erase(key);

            mp[key]=head->next;

            return val;
        }

        return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end()) 
        {
            Node* node=mp[key];
            node->val=value;
            deleteNode(node);
            addNode(node);
            return;
        }

        if(mp.size()==cap) 
        {
            Node* lru=tail->prev;
            int lruKey=lru->key;
            deleteNode(lru);
            mp.erase(lruKey);
            delete lru;
        }

        Node* newNode=new Node(key, value);
        addNode(newNode);
        mp[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */