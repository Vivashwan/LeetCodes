class NumArray {
private:
    vector<int>temp;
public:
    NumArray(vector<int>& nums) {
        int sum=0;

        for(auto it: nums)
        {
            sum+=it;
            temp.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        int r=temp[right];
        int l=0;

        if(left!=0)
        {
            l=temp[left-1];
        }   

        return r-l;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */