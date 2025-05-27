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
#define ll long long 
class Solution {
    public:
    ll res=0,total=0;
    int f(TreeNode* root)
    {
        if(!root)
        return 0;
        int sub= f(root->left)+f(root->right)+root->val;
        res=max(res,(total-sub)*sub);
        return sub;
    }
    int maxProduct(TreeNode* root)
    {
       total=f(root);
       f(root);
       return res%int(1e9+7);     
    }
};