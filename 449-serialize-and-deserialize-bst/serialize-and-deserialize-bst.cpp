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
        if(!root)
        {
            return "";
        }

        string str="";

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            if(it==nullptr)
            {
                str+="#,";
            }
            else
            {
                str+=to_string(it->val)+",";

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

        string s="";
        stringstream ss(data);
        getline(ss, s, ',');

        TreeNode* node=new TreeNode(stoi(s));
        queue<TreeNode*>q;

        q.push(node);

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            getline(ss, s, ',');

            if(s=="#")
            {
                it->left=nullptr;
            }
            else
            {
                TreeNode* nodeLeft=new TreeNode(stoi(s));
                it->left=nodeLeft;
                q.push(nodeLeft);
            }

            getline(ss, s, ',');

            if(s=="#")
            {
                it->right=nullptr;
            }
            else
            {
                TreeNode* nodeRight=new TreeNode(stoi(s));
                it->right=nodeRight;
                q.push(nodeRight);
            }
        }

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;