struct TrieNode {
    unordered_map<int, TrieNode*> children;
    TrieNode() {}
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        TrieNode* root=new TrieNode();
        int n=nums.size();
        int distinctCount=0;

        for(int i=0; i<n; i++) 
        {
            TrieNode* node=root;
            int divCount=0;

            for(int j=i; j<n; j++) 
            {
                if(nums[j]%p==0)
                { 
                    divCount++;
                }

                if(divCount>k)
                {
                    break;
                }

                if(!node->children.count(nums[j])) 
                {
                    node->children[nums[j]]=new TrieNode();
                    distinctCount++;
                }
                
                node=node->children[nums[j]];
            }
        }

        return distinctCount;
    }
};