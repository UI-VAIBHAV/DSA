/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> root_store;
        unordered_map<int, bool> is_child;

        for (int i = 0; i < descriptions.size(); i++) {
            int x = descriptions[i][0]; 
            int y = descriptions[i][1]; 
            bool is_left = descriptions[i][2];

            TreeNode* addrs_x = nullptr;
            TreeNode* addrs_y = nullptr;

            if (root_store.count(x)) {
                addrs_x = root_store[x];
            } else {
                addrs_x = new TreeNode(x);
                root_store[x] = addrs_x;
            }

            if (root_store.count(y)) {
                addrs_y = root_store[y];
            } else {
                addrs_y = new TreeNode(y);
                root_store[y] = addrs_y;
            }

            is_child[y] = true;

            if (is_left == 1) {
                addrs_x->left = addrs_y;
            } else {
                addrs_x->right = addrs_y;
            }
        }

        for (int i = 0; i < descriptions.size(); i++) {
            int parent = descriptions[i][0];

            if (is_child.count(parent) == 0) {
                return root_store[parent];
            }
        }

        return nullptr;
    }
};