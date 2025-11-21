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

        queue<TreeNode*>q;

        TreeNode* root=new TreeNode(stoi(s));

        q.push(root);

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
                TreeNode* newNode=new TreeNode(stoi(s));
                it->left=newNode;

                q.push(newNode);
            }

            getline(ss, s, ',');

            if(s=="#")
            {
                it->right=nullptr;
            }
            else
            {
                TreeNode* newNode=new TreeNode(stoi(s));
                it->right=newNode;

                q.push(newNode);
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