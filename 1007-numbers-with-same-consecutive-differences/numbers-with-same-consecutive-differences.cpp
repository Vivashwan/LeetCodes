class Solution {
private:
    void func(int remaining, int k, int current, vector<int>&result) 
    {
        if(remaining==0) 
        {
            result.push_back(current);
            return;
        }

        int lastDigit=current%10;

        for(int d=0; d<=9; d++) 
        {
            if(abs(d-lastDigit)==k) 
            {
                func(remaining-1, k, current*10+d, result);
            }
        }
    }

public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>result;
        
        for(int digit=1; digit<=9; digit++) 
        {
            func(n-1, k, digit, result);
        }
        
        return result;
    }
};