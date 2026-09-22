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
        if(!root){
            ans = max(ans,temp-1);
            return;
        }
        count(root->left,ans,temp+1);
        count(root->right,ans,temp+1);
        
    }
    int maxDepth(TreeNode* root) {
        int ans=0,temp=1;
        count(root,ans,temp);
        return ans;
    }
};