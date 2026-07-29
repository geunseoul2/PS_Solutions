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
    int max = -1001;

    int maxPathSum(TreeNode* root) {
        int temp = currPathSum(root);

        return max;
    }

    int currPathSum(TreeNode* root) {
        //max path sum is the max
        if(!root) return 0;
        
        //optimized my dirty code!
        int left = std::max(0,currPathSum(root->left));
        int right = std::max(0,currPathSum(root->right));

        max = std::max(max,left+right+root->val);

        return root->val + std::max(left,right);
    }
};
