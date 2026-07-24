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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //preorder -> root / left / right
        //inorder  -> left / root / right
        if(preorder.size() + inorder.size() == 0) return nullptr;

        // preorder/root check -> inorder/left tree check -> preorder/right tree check

        int root_val = preorder[0];
        auto root_it = find(inorder.begin(),inorder.end(),root_val);

        vector<int> in_l(inorder.begin(),root_it);
        vector<int> in_r(root_it+1,inorder.end());

        vector<int> pre_l(preorder.begin()+1,preorder.begin()+1+in_l.size());
        vector<int> pre_r(preorder.begin()+1+in_l.size(),preorder.end());

        TreeNode* root = new TreeNode(root_val);

        root->left = buildTree(pre_l,in_l);
        root->right = buildTree(pre_r,in_r);

        return root;
    }
};
