class Solution {
private:
    int func(vector<vector<int>>& books, int n, int shelfWidth, int currWidth, int ind, int currHeight, vector<vector<int>>&dp)
    {
        if(ind==n) 
        {
            return currHeight;
        }

        if(dp[ind][currWidth]!=-1)
        {
            return dp[ind][currWidth];
        }

        int minHeight=INT_MAX, newHeight=currHeight;

        if(currWidth-books[ind][0]>=0) 
        {
            newHeight = max(currHeight, books[ind][1]); 
            minHeight = min(minHeight, func(books, n, shelfWidth, currWidth-books[ind][0], ind+1, newHeight, dp));
        }

        minHeight = min(minHeight, currHeight+func(books, n, shelfWidth, shelfWidth-books[ind][0], ind+1, books[ind][1], dp));

        return dp[ind][currWidth]=minHeight;
    }

public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();

        vector<vector<int>>dp(n, vector<int>(shelfWidth+1, -1));
        return func(books, n, shelfWidth, shelfWidth, 0, 0, dp);
    }
};
