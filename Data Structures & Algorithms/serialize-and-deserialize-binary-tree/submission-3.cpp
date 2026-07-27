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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N";
        string res;
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (!node) {
                res += "N,";
            } else {
                res += to_string(node->val) + ",";
                queue.push(node->left);
                queue.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;
        if(data == "") return nullptr;
        stringstream ss(data);
        string temp;

        while(getline(ss,temp,',')) {
            if(!temp.empty()) {
                //arr.push_back(temp[0]);
                if(temp == "N") nodes.push_back(nullptr);
                else {
                    TreeNode* node = new TreeNode(stoi(temp));
                    nodes.push_back(node);
                }
            }
        }

        for(int i=0;i<nodes.size();i++) {
            if(nodes[i] == nullptr) continue;

            int left = 2*(i+1)-1;
            int right = 2*(i+1);

            if(left < nodes.size()) nodes[i]->left = nodes[left];
            if(right < nodes.size()) nodes[i]->right = nodes[right];
        }


        return nodes[0];
    }
};
