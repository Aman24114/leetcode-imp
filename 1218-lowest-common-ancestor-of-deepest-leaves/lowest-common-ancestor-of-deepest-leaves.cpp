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
    int f(TreeNode* root)
    {
        if(!root)
        return 0;
        return max(f(root->right),f(root->left))+1;
    }
    TreeNode* lca(TreeNode* root,int deep,int cur=1)
    {
        if(!root)
        return NULL;
        if(cur==deep)
        return root;
        TreeNode*left = lca(root->left,deep,cur+1);
        TreeNode*right= lca(root->right,deep,cur+1);
        if(left&&right)
        return root;
        return left ? left:right; 
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
       int deep=f(root);
       cout << deep << endl;
       return lca(root,deep);
    }
};