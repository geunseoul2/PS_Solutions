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
    int good = 0;

    int goodNodes(TreeNode* root) {
        //DFS
        if(!root) return 0;

        dfs(root,-101);

        return good;
    }

    void dfs(TreeNode* root,int max) {
        if(root->val >= max) {
            good++;
            max = root->val;
        }

        if(root->left) dfs(root->left,max);
        if(root->right) dfs(root->right,max);
    }
};