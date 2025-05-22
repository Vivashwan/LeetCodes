/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str="";

        if(!root)
        {
            return str;
        }

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            if(!it)
            {
                str+="#,";
            }
            else
            {
                str+=to_string(it->val)+',';

                q.push(it->left);
                q.push(it->right);
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
        {
            return nullptr;
        }

        string str="";
        stringstream x(data);
        getline(x, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            getline(x, str, ',');

            if(str=="#")
            {
                it->left=nullptr;
            }
            else
            {
                TreeNode* nextLeft = new TreeNode(stoi(str));

                it->left = nextLeft;

                q.push(nextLeft);
            }

            getline(x, str, ',');

            if(str=="#")
            {
                it->right=nullptr;
            }
            else
            {
                TreeNode* nextRight = new TreeNode(stoi(str));

                it->right = nextRight;

                q.push(nextRight);
            }
        }   

        return root;  
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;