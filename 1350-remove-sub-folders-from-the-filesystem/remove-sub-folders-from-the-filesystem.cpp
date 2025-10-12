struct Node{
    Node* links[27]={nullptr};
    bool isLeaf=false;

    bool containsKey(char ch)
    {
        return ch=='/' ? links[26]!=nullptr : links[ch-'a']!=nullptr;
    }

    Node* get(char ch)
    {
        return ch=='/' ? links[26] : links[ch-'a'];
    }

    void put(char ch, Node* node)
    {
        if(ch=='/')
        {
            links[26]=node;
        }
        else
        {
            links[ch-'a']=node;
        }
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

class Trie{
private:
    Node* root;

public: 
    Trie()
    {
        root=new Node();
    }

    void insert(string& folder)
    {
        Node* node=root;

        for(auto it: folder)
        {
            if(!node->containsKey(it))
            {
                node->put(it, new Node());
            }

            node=node->get(it);
        }

        node->setEnd();
    }

    bool isContains(string& folder)
    {
        Node* node=root;

        for(int i=0; i<folder.size(); i++) 
        {
            char ch=folder[i];

            if(node->isEnd()) 
            {
                if(i<folder.size() && folder[i]=='/') 
                {    
                    return true;
                }

                if(i==folder.size()) 
                {    
                    return true;
                }
            }

            if(!node->containsKey(ch))
            {
                return false;
            }

            node=node->get(ch);
        }

        return node->isEnd();
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        Trie trie;

        vector<string>res;

        for(auto it: folder)
        {
            if(!trie.isContains(it))
            {
                trie.insert(it);
                res.push_back(it);
            }
        }

        return res;
    }
};