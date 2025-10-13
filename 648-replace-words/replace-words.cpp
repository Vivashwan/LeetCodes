struct Node{
    Node* links[27]={nullptr};
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

class Trie{
public:
    Node* root;

    Trie(){
        root=new Node();
    }

    void insert(string& str)
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

    string findRoot(string& str)
    {
        Node* node=root;
        string prefix="";

        for(int i=0; i<str.length(); i++)
        {
            if(!node->hasKey(str[i]))
            {
                return "";
            }

            node=node->getKey(str[i]);
            prefix+=str[i];

            if(node->isEnd())
            {
                return prefix;
            }
        }

        return "";
    }

};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(auto it: dictionary)
        {
            trie.insert(it);
        }

        int left=0;
        string str="";

        for(int right=0; right<=sentence.size(); right++) 
        {
            if(right==sentence.size() || sentence[right]==' ') 
            {
                string word=sentence.substr(left, right-left);
                string root=trie.findRoot(word);

                if(!str.empty())
                { 
                    str+=" ";
                }

                str+=(root.empty() ? word : root);

                left=right+1;
            }
        }

        return str;
    }
};