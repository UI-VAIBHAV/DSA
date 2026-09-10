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
    int average(TreeNode* root,int &i){
        if(root==NULL) return 0;
        i++;
        return root->val + average(root->left,i) + average(root->right,i);
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        int cnt = 0;
        int sum = average(root,cnt);
        int match = (root->val == sum / cnt) ? 1 : 0;
        return match + averageOfSubtree(root->left) + averageOfSubtree(root->right);
    }
};