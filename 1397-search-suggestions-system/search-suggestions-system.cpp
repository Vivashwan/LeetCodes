struct Node{
    Node* links[26]={nullptr};
    bool isLeaf=false;

    bool hasKey(char ch)
    {
        return links[ch-'a']!=nullptr;
    }

    Node* getKey(char ch)
    {
        return links[ch -'a'];
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

class Trie{
public:
    Node* root;

    Trie()
    {
        root=new Node();
    }

    void update(string& str)
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
    void dfs(Node* node, string prefix, vector<string>&res)
    {
        if(res.size()==3)
        {
            return;
        }

        if(node->isEnd())
        {
            res.push_back(prefix);
        }

        for(char c='a'; c<='z'; c++)
        {
            if(node->hasKey(c))
            {
                prefix+=c;
                dfs(node->getKey(c), prefix, res);
                prefix.pop_back();
            }
        }
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        Trie trie;

        for(auto it: products)
        {
            trie.update(it);
        }

        vector<vector<string>>res;

        Node* node=trie.root;

        string prefix="";

        for(int i=0; i<searchWord.size(); i++)
        {
            prefix+=searchWord[i];

            if(node && node->hasKey(searchWord[i]))
            {
                node=node->getKey(searchWord[i]);

                string currentPrefix=prefix;

                vector<string>temp;

                dfs(node, currentPrefix, temp);

                res.push_back(temp);
            }
            else
            {
                node=nullptr;
                res.push_back({});
            }
        }

        return res;
    }
};