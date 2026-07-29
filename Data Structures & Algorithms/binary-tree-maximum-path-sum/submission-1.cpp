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
        
        int left = currPathSum(root->left);
        int right = currPathSum(root->right);
        // cout << left << " " << root->val << " " << right << endl;

        //update the max
        //left, left+root, right, right+root, left+root+right
        if(root->val > 0) {
            max = std::max(max,left+root->val);
            max = std::max(max,right+root->val);
        } else if(!root){
            max = std::max(max,left);
            max = std::max(max,right);
        }
        max = std::max(max, left+ root->val +right);

        //find the max route that can extend to parent node
        if(left < 0 && right < 0) {
            if(root->val < 0) return 0;
            return root->val;
        } else {
            if(left >= right && left+root->val>0) return  left+root->val;
            if(right >= left && right+root->val>0) return right+root->val;
            return 0;
        }
    }
};
