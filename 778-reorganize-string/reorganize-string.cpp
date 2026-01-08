class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for (char c : s) mp[c]++;

        priority_queue<pair<int, char>> pq;
        for (auto it : mp) pq.push({it.second, it.first});

        string res = "";

        while (pq.size() > 1)
        {
            vector<pair<int, char>> temp;

            for (int i = 0; i < 2; i++)
            {
                auto it = pq.top();
                pq.pop();

                res += it.second;
                it.first--;

                temp.push_back(it);
            }

            for (auto it : temp)
            {
                if (it.first > 0)
                    pq.push(it);
            }
        }

        // Case 1: nothing left
        if (pq.empty())
            return res;

        // Case 2: one char left
        if (pq.top().first > 1)
            return "";

        return res + pq.top().second;
    }
};
