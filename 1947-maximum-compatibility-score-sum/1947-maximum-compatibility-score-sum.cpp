class Solution {
public:
    
    int calculate(vector<vector<int>>& students, vector<vector<int>>& mentors, vector<int>& arr)
    {
        int n = students.size();
        
        // find the compatability for curr_combination
        
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {   
            for(int j = 0; j < students[i].size(); j++)
            {
                if(students[i][j] == mentors[arr[i]][j])
                    sum++;
            }
        }
        
        return sum;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        int n = students.size();
        
        // store the indexo of all mentors into array
        
        vector<int> arr(n);
        
        for(int i = 0; i < n; i++)
        {
            arr[i] = i;
        }
        
        int maxi = INT_MIN;
        
        // for every combination of mentor find the comapatability and take maximum of it
        
        do
        {
            // calculate compatability
            
            int ans = calculate(students, mentors, arr);
            
            // update maxi
            
            maxi = max(maxi, ans);
        }
        
        while(next_permutation(arr.begin(), arr.end()));
        
        return maxi;
    }
};