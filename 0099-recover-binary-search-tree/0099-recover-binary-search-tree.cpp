class Solution {
private:
    TreeNode* parent = nullptr;
    TreeNode* firstMisplaced = nullptr;
    TreeNode* secondMisplaced = nullptr;
    
    void findMisplaced(TreeNode* child) {
        if (child == nullptr) {
            return;
        }
        
        findMisplaced(child->left);
        
        if (parent != nullptr && child->val < parent->val) {
            if (firstMisplaced == nullptr) {
                firstMisplaced = parent;
            }
            secondMisplaced = child;
        }
        parent = child;
        
        findMisplaced(child->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        findMisplaced(root);
        
        if (firstMisplaced != nullptr && secondMisplaced != nullptr) {
            swap(firstMisplaced->val, secondMisplaced->val);
        }
    }
};
