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

class Solution {
private:
    bool dfs(string& s, int start, Trie& trie, unordered_map<int, bool>& memo)
    {
        if(start==s.size())
        { 
            return true;
        }

        if(memo.count(start))
        { 
            return memo[start];
        }

        Node* node=trie.root;

        for(int i=start; i<s.size(); i++) 
        {
            char ch=s[i];
            if(!node->hasKey(ch))
            { 
                break;
            }

            node=node->getKey(ch);

            if(node->isEnd() && dfs(s, i+1, trie, memo)) 
            {
                return memo[start]=true;
            }
        }

        return memo[start]=false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;

        for(string& word: wordDict)
        {    
            trie.insert(word);
        }

        unordered_map<int, bool>memo;

        return dfs(s, 0, trie, memo);
    }
};