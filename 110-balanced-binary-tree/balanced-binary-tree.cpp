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
    int height(TreeNode* root,bool &check){
        if(!root) return 0;
        int left = height(root->left,check);
        int right = height(root->right,check);
        if(abs(left-right)>1) check =0;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool check=1;
        height(root,check);
        return check;
    }
};