struct Node{
    Node* links[27]={nullptr};
    bool isLeaf=false;

    bool hasKey(char ch)
    {
        return links[ch-'a']!=nullptr;
    }

    void putKey(char ch, Node* node)
    {
        links[ch-'a']=node;
    }

    Node* getKey(char ch)
    {
        return links[ch-'a'];
    }

    bool isEnd()
    {
        return isLeaf;
    }

    void setEnd()
    {
        isLeaf=true;
    }
};
class Trie {
private:
    Node* node;
public:
    Trie() {
        node=new Node();
    }
    
    void insert(string word) {
        Node* root=node;

        for(int i=0; i<word.length(); i++)
        {
            if(!root->hasKey(word[i]))
            {
                root->putKey(word[i], new Node());
            }

            root=root->getKey(word[i]);
        }

        root->setEnd();
    }
    
    bool search(string word) {
        Node* root=node;

        for(int i=0; i<word.length(); i++)
        {
            if(!root->hasKey(word[i]))
            {
                return false;
            }

            root=root->getKey(word[i]);
        }

        return root->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* root=node;

        for(int i=0; i<prefix.length(); i++)
        {
            if(!root->hasKey(prefix[i]))
            {
                return false;
            }

            root=root->getKey(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Node object will be instantiated and called as such:
 * Node* obj = new Node();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */