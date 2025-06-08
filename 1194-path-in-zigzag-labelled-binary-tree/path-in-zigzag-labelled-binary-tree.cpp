class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>res;

        int temp=label, level=0;

        while(temp!=0)
        {
            temp/=2;
            level++;
        }

        while(label>=1)
        {
            res.push_back(label);

            int levelStart=pow(2, level-1), levelEnd=pow(2, level)-1;

            label=levelStart+(levelEnd-label);

            label/=2;
            level--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};