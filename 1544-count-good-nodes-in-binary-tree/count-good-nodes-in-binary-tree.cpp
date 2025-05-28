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
int ans=0;
    void f(TreeNode* root,int curr)
    {
        if(root==NULL)
        return;
        if(root->val>=curr)
        { 
            curr=root->val;
            ans++;
        }
        f(root->left,curr);
        f(root->right,curr);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)
        return 0;
        f(root,root->val);
        return ans;
    }
};