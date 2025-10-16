struct Node {
    Node* links[26] = {nullptr};
    bool isLeaf = false;

    bool hasKey(char ch) { return links[ch - 'a'] != nullptr; }
    Node* getKey(char ch) { return links[ch - 'a']; }
    void putKey(char ch, Node* node) { links[ch - 'a'] = node; }
    void setEnd() { isLeaf = true; }
    bool isEnd() { return isLeaf; }
};

class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }

    void insert(const string& word) {
        Node* node = root;
        for (char c : word) {
            if (!node->hasKey(c))
                node->putKey(c, new Node());
            node = node->getKey(c);
        }
        node->setEnd();
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        for (auto& word : dictionary)
            trie.insert(word);

        int n = s.size();
        vector<int> dp(n + 1, 0);

        // Base case
        dp[n] = 0;

        // Build dp from end → start
        for (int i = n - 1; i >= 0; i--) {
            // Option 1: Treat current char as extra
            dp[i] = 1 + dp[i + 1];

            // Option 2: Try to match dictionary words starting at i
            Node* node=trie.root;
            for(int j=i; j<n; j++) {
                if(!node->hasKey(s[j])) break;
                node=node->getKey(s[j]);

                if(node->isEnd()) 
                {
                    dp[i] = min(dp[i], dp[j+1]);
                }
            }
        }

        return dp[0];
    }
};
