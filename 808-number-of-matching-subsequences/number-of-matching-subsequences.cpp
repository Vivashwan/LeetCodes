struct Node {
    Node* links[26]={nullptr};
    int endCount=0;
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
        endCount++;
        word=w;
    }

    bool isEnd() 
    { 
        return endCount>0;
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
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        Trie trie;
        
        for(auto& w: words)
        {    
            trie.insert(w);
        }

        vector<vector<Node*>>waiting(26);

        for(int i=0; i<26; i++)
        {    
            if(trie.root->links[i])
            {    
                waiting[i].push_back(trie.root->links[i]);
            }
        }

        int result=0;

        for(char ch: s) 
        {
            int idx=ch-'a';
            auto curr=waiting[idx];
            waiting[idx].clear();

            for(auto node: curr) 
            {
                if(node->endCount>0)
                {    
                    result+=node->endCount;
                }

                for(int j=0; j<26; j++)
                {   
                    if(node->links[j])
                    {    
                        waiting[j].push_back(node->links[j]);
                    }
                }
            }
        }

        return result;
    }
};
