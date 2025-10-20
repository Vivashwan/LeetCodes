struct Node {
    Node* links[26]={nullptr};
    bool isLeaf=false;

    bool hasKey(char ch) 
    { 
        return links[ch-'a']!=nullptr; 
    }

    Node* getKey(char ch) 
    { 
        return links[ch-'a']; 
    }

    void putKey(char ch, Node* node) 
    { 
        links[ch-'a']=node;
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
public:
    Node* root;

    Trie() 
    { 
        root=new Node(); 
    }

    void insert(string& word) 
    {
        Node* node=root;

        for(char ch: word) 
        {
            if(!node->hasKey(ch)) 
            {
                node->putKey(ch, new Node());
            }
            node=node->getKey(ch);
        }

        node->setEnd();
    }
};

class WordDictionary {
private:
    Trie trie;

    bool searchHelper(string& word, Node* node, int index) 
    {
        if(index==word.size())
        { 
            return node->isEnd();
        }

        char ch=word[index];
        
        if(ch=='.') 
        {
            for(int i=0; i<26; i++) 
            {
                if(node->links[i] && searchHelper(word, node->links[i], index+1)) 
                {
                    return true;
                }
            }

            return false;
        } 
        else 
        {
            if(!node->hasKey(ch)) 
            {
                return false;
            }

            return searchHelper(word, node->getKey(ch), index+1);
        }
    }

public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie.insert(word);
    }
    
    bool search(string word) {
        return searchHelper(word, trie.root, 0);   
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */