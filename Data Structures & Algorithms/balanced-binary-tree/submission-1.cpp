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
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* node = root;
        TreeNode* last = nullptr;
        unordered_map<TreeNode*, int> depth;

        while(!stack.empty() || node != nullptr) {
            if(node != nullptr) {
                stack.push(node);
                node = node->left; //Depth First Search
            } else {
                node = stack.top();
                if(node->right == nullptr || last == node->right) { //if the node has traver
                    stack.pop();
                    int left = depth[node->left];
                    int right = depth[node->right];
                    if(abs(left-right) > 1) return false;
                    depth[node] = 1 + max(left,right);
                    last = node;
                    node = nullptr;
                } else node = node->right;
            }
        }

        return true;
    }
};
