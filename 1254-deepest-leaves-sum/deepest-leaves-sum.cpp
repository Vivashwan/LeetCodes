class Solution {
private:
    int getMaxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getMaxDepth(root->left), getMaxDepth(root->right));
    }

    void getSumAtDepth(TreeNode* root, int currentDepth, int targetDepth, int& sum) {
        if (!root) return;
        if (currentDepth == targetDepth) {
            sum += root->val;
        }
        getSumAtDepth(root->left, currentDepth + 1, targetDepth, sum);
        getSumAtDepth(root->right, currentDepth + 1, targetDepth, sum);
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = getMaxDepth(root);
        int sum = 0;
        getSumAtDepth(root, 1, maxDepth, sum);
        return sum;
    }
};
