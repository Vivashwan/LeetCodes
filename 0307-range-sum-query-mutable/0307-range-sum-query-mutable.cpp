class NumArray {
private:
    vector<int> nums;
    vector<int> BIT;
    int n;

    // Helper function to add value to BIT
    void add(int index, int val) {
        index++; // BIT is 1-indexed
        while (index <= n) {
            BIT[index] += val;
            index += index & -index;
        }
    }

    // Helper function to get prefix sum from BIT
    int prefixSum(int index) {
        int sum = 0;
        index++; // BIT is 1-indexed
        while (index > 0) {
            sum += BIT[index];
            index -= index & -index;
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        BIT = vector<int>(n + 1, 0); // BIT is 1-indexed, hence size n + 1

        // Initialize BIT with given nums
        for (int i = 0; i < n; ++i) {
            add(i, nums[i]);
        }
    }

    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] = val;
        add(index, delta);
    }

    int sumRange(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */