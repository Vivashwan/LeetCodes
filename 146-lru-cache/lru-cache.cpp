class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;

        Node* next;
        Node* prev;

        Node(int _key, int _val)
        {
            key=_key;
            val=_val;
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

    void deleteNode(Node* newNode)
    {
        Node* newNodeNext=newNode->next;
        Node* newNodePrev=newNode->prev;

        newNode->prev=nullptr;

        newNodePrev->next=newNodeNext;
        newNodeNext->prev=newNodePrev;
    }

    void addNode(Node* newNode)
    {
        Node* newNodeNext=head->next;
        
        head->next=newNode;
        newNode->prev=head;

        newNode->next=newNodeNext;
        newNodeNext->prev=newNode;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            auto it=mp[key];
            int res=it->val;

            mp.erase(key);

            deleteNode(it);
            addNode(it);

            mp[key]=head->next;

            return res;            
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            auto it=mp[key];

            deleteNode(it);
            mp.erase(key);
        }

        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */