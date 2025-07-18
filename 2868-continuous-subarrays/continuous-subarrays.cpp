class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        set<int>seen;
        deque<int>minQ, maxQ;
        int l=0;
        long long res=0;

        for(int r=0; r<n; r++)
        {
            while(!minQ.empty() && nums[r]<minQ.back())
            { 
                minQ.pop_back();
            }

            minQ.push_back(nums[r]);

            while(!maxQ.empty() && nums[r]>maxQ.back())
            { 
                maxQ.pop_back();
            }

            maxQ.push_back(nums[r]);

            seen.insert(nums[r]);

            while((maxQ.front()-minQ.front()>2) || seen.count(nums[r])>1)
            {
                seen.erase(nums[l]);

                if(!minQ.empty() && minQ.front()==nums[l])
                { 
                    minQ.pop_front();
                }

                if(!maxQ.empty() && maxQ.front()==nums[l])
                { 
                    maxQ.pop_front();
                }

                l++;
            }

            res+=(r-l+1);
        }

        return res;
    }
};
