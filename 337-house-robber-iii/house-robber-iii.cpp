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
    unordered_map<TreeNode*,int>dp;
    int f(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        if(dp.count(root))
        {
            return dp[root];
        }
        int t=root->val;
        if(root->left!=NULL)
        {
            t+=f(root->left->left)+f(root->left->right);
        }
        if(root->right!=NULL)
        {
            t+=f(root->right->left)+f(root->right->right);
        }
        int nt=f(root->left)+f(root->right);
        int ans=max(t,nt);
        dp[root]=ans;
        return ans;
    }
    int rob(TreeNode* root)
    {
        return  f(root);   
    }
};;