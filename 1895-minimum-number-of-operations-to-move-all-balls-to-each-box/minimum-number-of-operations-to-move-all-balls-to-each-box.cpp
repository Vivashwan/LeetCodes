class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();

        vector<int>onesIndices;
        
        for(int i=0; i<n; i++)
        {
            if(boxes[i]=='1')
            {
                onesIndices.push_back(i);
            }
        }   

        int m = onesIndices.size();

        vector<int>res;

        for(int i=0; i<n; i++)
        {
            int val = 0;
            for(int j=0; j<m; j++)
            {
                val+=abs(onesIndices[j]-i);
            }

            res.push_back(val);
        }

        return res;
    }
};