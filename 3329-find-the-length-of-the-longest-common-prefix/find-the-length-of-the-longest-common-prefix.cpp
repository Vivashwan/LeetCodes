struct Node {
    Node* links[10]={nullptr};
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
        links[ch - '0']=node;
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

    void insert(string& str) 
    {
        Node* node=root;
        for(char c: str) 
        {
            if(!node->hasKey(c))
            {    
                node->putKey(c, new Node());
            }

            node=node->getKey(c);
        }

        node->setEnd();
    }

    int getPrefixLength(string& str) 
    {
        Node* node=root;
        int length=0;

        for(char c: str) 
        {
            if(!node->hasKey(c))
            { 
                break;
            }

            node=node->getKey(c);

            length++;
        }

        return length;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;

        for(int num: arr1) 
        {
            string s=to_string(num);
            trie.insert(s);
        }

        int ans=0;

        for(int num: arr2) 
        {
            string s=to_string(num);

            ans=max(ans, trie.getPrefixLength(s));
        }

        return ans;
    }
};