struct Node 
{
    Node* links[52]={nullptr};
    bool isLeaf=false;

    bool hasKey(char ch) 
    {
        int idx=(isupper(ch) ? ch-'A'+26 : ch-'a');
        return links[idx]!=nullptr;
    }

    Node* getKey(char ch) 
    {
        int idx=(isupper(ch) ? ch-'A'+26 : ch-'a');
        return links[idx];
    }

    void putKey(char ch, Node* node) 
    {
        int idx=(isupper(ch) ? ch-'A'+26 : ch-'a');
        links[idx]=node;
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

    void insert(string& pattern) 
    {
        Node* node=root;

        for(char ch: pattern) 
        {
            if(!node->hasKey(ch))
            {    
                node->putKey(ch, new Node());
            }

            node=node->getKey(ch);
        }

        node->setEnd();
    }

    bool match(Node* node, string& query, int i) 
    {
        if(i==query.size())
        {    
            return node->isEnd();
        }

        char ch=query[i];
        
        if(node->hasKey(ch)) 
        {
            if(match(node->getKey(ch), query, i+1))
            {    
                return true;
            }
        }

        if(islower(ch))
        {    
            return match(node, query, i+1);
        }

        return false;
    }
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Trie trie;
        trie.insert(pattern);
        vector<bool>ans;

        for(auto& q: queries)
        {    
            ans.push_back(trie.match(trie.root, q, 0));
        }

        return ans;
    }
};
