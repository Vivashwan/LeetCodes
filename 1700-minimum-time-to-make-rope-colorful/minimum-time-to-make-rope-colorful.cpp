class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();

        if(n==1)
        {
            return 0;
        }

        stack<pair<char, int>>st;

        st.push({colors[0], neededTime[0]});

        int count=0;

        for(int i=1; i<n; i++)
        {
            if(!st.empty() && st.top().first==colors[i])
            {
                if(st.top().second <= neededTime[i])
                {
                    count+=st.top().second;
                    st.pop();

                    st.push({colors[i], neededTime[i]});
                }
                else if(neededTime[i] < st.top().second)
                {
                    count+=neededTime[i];
                }
            }
            else if(!st.empty() && st.top().first!=colors[i])
            {
                while(!st.empty())
                {
                    st.pop();
                }

                st.push({colors[i], neededTime[i]});
            }
            else if(st.empty())
            {
                st.push({colors[i], neededTime[i]});
            }
        }

        return count;
    }
};