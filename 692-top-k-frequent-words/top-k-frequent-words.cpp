struct Node {
    Node* links[26]={nullptr};
    bool isLeaf=false;
    int freq=0;

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
        freq++;
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

        for(char ch: str) 
        {
            if(!node->hasKey(ch)) 
            {
                node->putKey(ch, new Node());
            }
            node=node->getKey(ch);
        }

        node->setEnd();
    }

    void collect(Node* node, string current, unordered_map<string, int>& freqMap) 
    {
        if(node->isEnd()) 
        {
            freqMap[current]+=node->freq;
        }

        for(char c='a'; c<='z'; c++) 
        {
            if(node->hasKey(c)) 
            {
                collect(node->getKey(c), current+c, freqMap);
            }
        }
    }

    unordered_map<string, int>getAllWords() 
    {
        unordered_map<string, int>freqMap;
        collect(root, "", freqMap);
        return freqMap;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        Trie trie;

        for(auto& w: words) 
        {
            trie.insert(w);
        }

        unordered_map<string, int>freqMap=trie.getAllWords();

        vector<pair<string, int>>freqList(freqMap.begin(), freqMap.end());

        sort(freqList.begin(), freqList.end(), [](auto& a, auto& b) 
        {
            if(a.second==b.second)
            {    
                return a.first<b.first;
            }

            return a.second>b.second; 
        });

        vector<string>result;

        for(int i=0; i<k && i<freqList.size(); i++) 
        {
            result.push_back(freqList[i].first);
        }

        return result;
    }
};