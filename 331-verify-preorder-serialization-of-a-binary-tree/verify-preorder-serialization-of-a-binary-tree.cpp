class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) 
        {
            return false;
        }

        preorder+=',';

        int n=preorder.length(), slots=1;

        for(int i=0; i<n; i++)
        {
            if(preorder[i]!=',')
            {
                continue;
            }

            slots--;

            if(slots<0)
            {
                return false;
            }

            if(preorder[i-1]!='#')
            {
                slots+=2;
            }
        }

        return slots==0;
    }
};