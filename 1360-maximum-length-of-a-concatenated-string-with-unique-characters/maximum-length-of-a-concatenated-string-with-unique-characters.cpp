class Solution {
private:
    int maxim=INT_MIN;

    void func(vector<string>&arr, int n, unordered_set<char>s, int ind, string str)
    {
        if(ind==n)
        {
            int size=str.length();
            maxim=max(maxim, size);
            return;
        }

        func(arr, n, s, ind+1, str);

        for(auto it: arr[ind])
        {
            if(s.find(it)!=s.end())
            {
                return;
            }

            s.insert(it);
        }

        str+=arr[ind];

        func(arr, n, s, ind+1, str);
    }
public:
    int maxLength(vector<string>& arr) {
        int n=arr.size();

        unordered_set<char>s;

        string str="";

        func(arr, n, s, 0, str);

        return maxim;
    }
};