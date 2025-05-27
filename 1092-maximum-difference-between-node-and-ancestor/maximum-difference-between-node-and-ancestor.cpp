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
    int diff=0;
    int maxAncestorDiff(TreeNode* root)
    {
      if(!root)
      return 0;
      int minval= root->val,maxval=root->val;
      f(root,minval,maxval);
      return diff; 
    }
    void f(TreeNode* root,int mini,int maxi)
    {
        if(!root)
        return;
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        diff = max(diff,max(abs(mini-root->val), abs(maxi- root->val)));
        f(root->left,mini,maxi);
        f(root->right,mini,maxi);
    }
};