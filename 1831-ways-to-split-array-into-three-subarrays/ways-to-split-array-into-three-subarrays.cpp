class Solution {
public:
        int mod = 1e9 + 7;
    
    int find_left_boundary(vector<int> &arr, int start, int end, int i, int n)
    {
        int left_boundary = n;
        
        while(start <= end)
        {
            int mid = (start + end) / 2;
            
            if(arr[mid] >= 2 * arr[i])
            {
                left_boundary = mid;
                
                end = mid - 1;
            }
            
            else{
                
                start = mid + 1;
            }
        }
        
        return left_boundary;
    }
    
    int find_right_boundary(vector<int> &arr, int start, int end, int i, int n)
    {
        int right_boundary = i;
        
        while(start <= end)
        {
            int mid = (start + end) / 2;
            
            if(arr[mid] <= (arr[n-1] + arr[i]) / 2)
            {
                right_boundary = mid;
                
                start = mid + 1;
            }
            
            else{
                
                end = mid - 1;
            }
        }
        
        return right_boundary;
    }
    
    int waysToSplit(vector<int>& arr) {
        
        int n = arr.size();
        
        int ans = 0;
        
        for(int i = 1; i < n; i++)
        {
            arr[i] += arr[i-1];
        }
        
        for(int i = 0; i <= n - 3; i++)
        {
            int left_boundary = find_left_boundary(arr, i + 1, n - 2, i, n);
            
            int right_boundary = find_right_boundary(arr, i + 1, n - 2, i, n);
            
            if(right_boundary >= left_boundary)
            {
                ans = (ans % mod + (right_boundary - left_boundary + 1) % mod ) % mod;
            }
        }
        
        return ans;
    }
};