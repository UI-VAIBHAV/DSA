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
    void count(TreeNode* root,int &ans,int temp){
        if(!root->left  && !root->right){
            ans = min(ans,temp);
            return;
        }
        if(root->left) count(root->left,ans,temp+1);
        if(root->right) count(root->right,ans,temp+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MAX,temp=0;
        count(root,ans,1);
        return ans;
    }
};