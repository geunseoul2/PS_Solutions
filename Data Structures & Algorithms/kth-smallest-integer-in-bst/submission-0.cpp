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
    int ans = 0;
    int th = 0;

    int kthSmallest(TreeNode* root, int k) {
        //inorder tree walk
        th = k;
        dfs(root);

        return ans;
    }

    void dfs(TreeNode* root) {
        if(!root) return;
        
        dfs(root->left);
        th--;

        if(th == 0) {
            ans = root->val;
            return;
        }

        dfs(root->right);
        return;
    }
};
