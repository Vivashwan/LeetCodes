class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, 
                vector<int>& rowCosts, vector<int>& colCosts) {
        
        int r1=startPos[0], c1=startPos[1];
        int r2=homePos[0],  c2=homePos[1];
        
        int cost=0;
        
        if(r1<r2) 
        {
            for(int r=r1+1; r<=r2; r++)
            {    
                cost+=rowCosts[r];
            }
        } 
        else 
        {
            for(int r=r1-1; r>=r2; r--)
            {    
                cost+=rowCosts[r];
            }
        }

        if(c1<c2) 
        {
            for(int c=c1+1; c<=c2; c++)
            {    
                cost+=colCosts[c];
            }
        } 
        else 
        {
            for(int c=c1-1; c>=c2; c--)
            {    
                cost+=colCosts[c];
            }
        }
        
        return cost;
    }
};
