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
    int h1(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        return max(h1(root->left),h1(root->right))+1;
    }
    int sum=0;
    int f(TreeNode* root,int h,int s)
    {   
        if(root==NULL)
        return 0;
        if(s==h)
        return root->val;
        return f(root->left,h,s+1)+f(root->right,h,s+1);
    }
    int deepestLeavesSum(TreeNode* root) {
       int h=h1(root),s=1;
       return f(root,h,s); 
    }
};
