class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();

        vector<bool>isPrime(1001, true);

        isPrime[0]=isPrime[1]=false;

        for(int i=2; i*i<=1000; i++)
        {
                if(isPrime[i])
                {
                    for(int j=i*i; j<=1000; j+=i)
                    {
                        isPrime[j]=false;
                    }
                }
        }

        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]<nums[i+1])
            {
                continue;
            }

            bool isChanged=false;

            for(int newVal=nums[i+1]-1; newVal>=0; newVal--)
            {
                int prime=nums[i]-newVal;

                if(prime>0 && prime<nums[i] && isPrime[prime])
                {
                    nums[i]=newVal;
                    isChanged=true;
                    break;
                }
            }

            if(!isChanged)
            {
                return false;
            }
        }

        return true;
    }
};