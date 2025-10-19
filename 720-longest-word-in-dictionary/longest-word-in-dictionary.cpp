struct Node 
{
    Node* links[26]={nullptr};
    bool isLeaf=false;
    string word="";

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

    void setEnd(string w) 
    { 
        isLeaf=true;
        word=w;
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

        node->setEnd(word);
    }
};

class Solution {
private:
    void dfs(Node* node, string& result) 
    {
        if(node==nullptr)
        {
            return;
        }

        if(node->isEnd()) 
        {
            if(node->word.size()>result.size() || (node->word.size()==result.size() && node->word<result)) 
            {
                result=node->word;
            }
        }

        for(int i=0; i<26; i++) 
        {
            if(node->links[i] && node->links[i]->isEnd())
            {    
                dfs(node->links[i], result);
            }
        }
    }

public:
    string longestWord(vector<string>& words) {
        Trie trie;

        for(auto& w: words) 
        {
            trie.insert(w);
        }

        string result="";

        dfs(trie.root, result);

        return result;
    }
};