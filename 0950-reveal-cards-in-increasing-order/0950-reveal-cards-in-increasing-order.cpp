class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        queue<int>q;

        int i=0, n=deck.size();

        while(i<n)
        {
            q.push(i);
            i++;
        }

        vector<int>res(n);

        for(int i=0; i<n; i++)
        {
            res[q.front()]=deck[i];
            q.pop();

            q.push(q.front());
            q.pop();
        }

        return res;
    }
};