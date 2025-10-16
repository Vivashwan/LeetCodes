struct Node{
    Node* links[26]={nullptr};
    bool isLeaf=true;

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
        isLeaf=false;
    }
};

class Trie{
public:
    Node* root;

    Trie(){
        root=new Node();
    }

    Node* insertReversed(string& word) 
    {
        Node* node=root;

        for(int i=word.size()-1; i>=0; i--) 
        {
            char ch=word[i];

            if(!node->hasKey(ch))
            {
                node->putKey(ch, new Node());
            }

            node=node->getKey(ch);
        }

        return node;
    }
};

class Solution {
private:
    static bool myCmp(string &a, string &b)
    {
        return a.size()>b.size();
    }

public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie trie;
        unordered_map<Node*, int>nodes;
        sort(words.begin(), words.end(), myCmp);

        for(auto &word: words) 
        {
            Node* node=trie.insertReversed(word);
            nodes[node]=word.size();
        }

        int res=0;
        for(auto &[node, len]: nodes) 
        {
            if(node->isLeaf) 
            {
                res+=len+1;
            }
        }

        return res;
    }
};