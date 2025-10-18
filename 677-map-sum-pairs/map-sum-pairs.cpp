class MapSum {
public:
    struct Node 
    {
        Node* links[26]={nullptr};
        int sum=0;
    };

    Node* root;
    unordered_map<string, int>mp;

    MapSum() {
        root=new Node();
    }

    void insert(string key, int val) {
        int diff=val;

        if(mp.find(key)!=mp.end()) 
        {
            diff-=mp[key];
        }
        
        mp[key]=val;

        Node* node=root;

        for(char ch: key) 
        {
            if(!node->links[ch-'a']) 
            {
                node->links[ch-'a']=new Node();
            }

            node=node->links[ch-'a'];
            node->sum+=diff;
        }
    }

    int sum(string prefix) {
        Node* node=root;

        for(char ch: prefix) 
        {
            if(!node->links[ch-'a'])
            { 
                return 0;
            }

            node=node->links[ch-'a'];
        }

        return node->sum;
    }
};
