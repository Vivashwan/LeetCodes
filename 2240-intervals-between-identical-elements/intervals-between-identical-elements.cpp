class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n=arr.size();
        vector<long long>answer(n, 0);
        
        unordered_map<int, long long>countMap, sumMap;

        for(int i=0; i<n; i++) 
        {
            int num=arr[i];

            answer[i]+=countMap[num] * (long long)i - sumMap[num];

            countMap[num]+=1;
            sumMap[num]+=i;
        }

        countMap.clear();
        sumMap.clear();

        for(int i=n-1; i>=0; i--) 
        {
            int num=arr[i];

            answer[i]+=sumMap[num] - countMap[num] * (long long)i;

            countMap[num]+=1;
            sumMap[num]+=i;
        }

        return answer;
    }
};