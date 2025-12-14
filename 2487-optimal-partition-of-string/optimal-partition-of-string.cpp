class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>se;
        int count=1;

        for(char c: s)
        {
            if(se.count(c)) 
            {
                count++;
                se.clear();
            }
            se.insert(c);
        }

        return count;
    }
};
