struct Node{
    Node* link[27]={nullptr};
    bool isLeaf=false;

    bool hasKey(char ch)
    {
        return link[ch-'a'] != nullptr;
    }

    Node* getKey(char ch)
    {
        return link[ch-'a'];
    }

    void putKey(char ch, Node* node)
    {
        link[ch-'a']=node;
    }

    void setEnd()
    {
        isLeaf=true;
    }

    bool isEnd()
    {
        return isLeaf;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;

        for(int i=0; i<word.length(); i++)
        {
            if(!node->hasKey(word[i]))
            {
                node->putKey(word[i], new Node());
            }

            node=node->getKey(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;

        for(int i=0; i<word.length(); i++)
        {
            if(!node->hasKey(word[i]))
            {
                return false;
            }

            node=node->getKey(word[i]);
        }

        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;

        for(int i=0; i<prefix.length(); i++)
        {
            if(!node->hasKey(prefix[i]))
            {
                return false;
            }

            node=node->getKey(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */