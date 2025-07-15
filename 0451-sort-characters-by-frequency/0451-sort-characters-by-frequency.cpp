class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();

        unordered_map<char, int>mp;

        for(auto it: s)
        {
            mp[it]++;
        }

        priority_queue<pair<int, char>>pq;

        for(auto it: mp)
        {
            pq.push({it.second, it.first});
        }

        string str="";

        while(!pq.empty())
        {
            auto it=pq.top();
            int freq=it.first;
            char ch=it.second;

            pq.pop();

            for(int i=0; i<freq;i++)
            {
                str+=ch;
            }
        }

        return str;
    }
};