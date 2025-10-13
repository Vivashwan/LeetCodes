struct Node{
    Node* links[27]={nullptr};
    bool isLeaf=false;

    bool hasKey(char ch)
    {
        return links[ch-'0']!=nullptr;
    }

    Node* getKey(char ch)
    {
        return links[ch-'0'];
    }

    void putKey(char ch, Node* node)
    {
        links[ch-'0']=node;
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
public:
    Node* root;
    Trie()
    {
        root=new Node();
    }

    void insert(string str)
    {
        Node* node=root;

        for(int i=0; i<str.length(); i++)
        {
            if(!node->hasKey(str[i]))
            {
                node->putKey(str[i], new Node());
            }

            node=node->getKey(str[i]);
        }

        node->setEnd();
    }
};

class Solution {
private:
    void dfs(Node* node, string& path, vector<int>&res)
    {
        if(node->isEnd())
        {
            res.push_back(stoi(path));
        }

        for(int i=0; i<10; i++)
        {
            if(node->links[i])
            {
                path.push_back('0'+i);

                dfs(node->links[i], path, res);

                path.pop_back();
            }
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        Trie trie;

        for(int i=1; i<=n; i++)
        {
            trie.insert(to_string(i));
        }

        vector<int>res;

        string path="";

        dfs(trie.root, path, res);

        return res;
    }
};