class CombinationIterator {
public:
    queue<string>q;
    
    void sol(string characters, int combinationLength, int index, string cur)
    {
        if(cur.size()==combinationLength)
        {
            q.push(cur);
            return;
        }

        for(int i=index; i<characters.size(); i++)
        {
            sol(characters, combinationLength, i+1, cur+characters[i]);
        }
    }

    CombinationIterator(string characters, int combinationLength) {
        sol(characters, combinationLength, 0, "");    
    }
    
    string next() {
        string ret=q.front();
        q.pop();
        return ret;    
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */