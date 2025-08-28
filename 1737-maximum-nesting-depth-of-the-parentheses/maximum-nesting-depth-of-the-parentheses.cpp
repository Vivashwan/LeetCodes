class Solution {
public:
    int maxDepth(string s) {
        int maxim=0, count=0;

        for(auto it: s)
        {
            if(it=='(')
            {
                count++;

                maxim=max(maxim, count);
            }
            else if(it==')')
            {
                count--;
            }

        }

        return maxim;
    }
};