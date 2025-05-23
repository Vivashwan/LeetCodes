/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    TreeNode* root;
    priority_queue<int,vector<int>, greater<int>>pq;

    void inorderTraversal(TreeNode* root)
    {
        if(root)
        {
            inorderTraversal(root->left);
            pq.push(root->val);
            inorderTraversal(root->right);
        }
    }

public:
    BSTIterator(TreeNode* root) {
        this->root=root;
        inorderTraversal(root);
    }
    
    int next() {
        int top = pq.top();
        pq.pop();

        return top;
    }
    
    bool hasNext() {
        return (!pq.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */