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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //BFS
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> line;
        line.push(root);

        while(!line.empty()) {
            vector<int> level;
            int size = line.size();
            
            for(int i=0;i<size;i++) {
                TreeNode* front = line.front();
                line.pop();
                if(front) {
                    line.push(front->left);
                    line.push(front->right);
                    level.push_back(front->val);
                }
            }

            if(!level.empty()) ans.push_back(level);
        }

        return ans;
    }
};
