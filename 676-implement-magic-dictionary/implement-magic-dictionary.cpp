class MagicDictionary {
public:
    struct Node 
    {
        Node* links[26]={nullptr};
        bool isEnd=false;
    };

    Node* root;

    MagicDictionary() {
        root=new Node();
    }

    void insert(string &word) 
    {
        Node* node=root;

        for(char ch: word) 
        {
            int idx=ch-'a';

            if(!node->links[idx])
            { 
                node->links[idx]=new Node();
            }

            node=node->links[idx];
        }

        node->isEnd=true;
    }

    void buildDict(vector<string>dictionary) 
    {
        for(auto &w: dictionary) 
        {
            insert(w);
        }
    }

    bool dfs(Node* node, string &word, int pos, bool modified) 
    {
        if(!node)
        {
            return false;
        }

        if(pos==word.size())
        { 
            return modified && node->isEnd;
        }

        int idx=word[pos]-'a';

        for(int i=0; i<26; i++) 
        {
            if(!node->links[i])
            { 
                continue;
            }

            if(i==idx) 
            {
                if(dfs(node->links[i], word, pos+1, modified))
                {
                    return true;
                }
            } 
            else if(!modified) 
            {
                if(dfs(node->links[i], word, pos+1, true))
                {
                    return true;
                }
            }
        }
        
        return false;
    }

    bool search(string searchWord) {
        return dfs(root, searchWord, 0, false);
    }
};
