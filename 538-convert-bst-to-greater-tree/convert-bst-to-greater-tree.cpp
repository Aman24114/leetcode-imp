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
 */ // given root of binary search tree 
 // greater tree will have the rootsum plus the sum of all roots which are greater than the the given root 
 // we will do an inorder traversal in tha array
 // then update the array by traversing the array 
 // 
class Solution {
public:
    void in(TreeNode* root,vector<int>&inorder)
    {
        if(!root)
        return;
        in(root->left,inorder);
        inorder.push_back(root->val);
        in(root->right,inorder);
    }
    void f1(TreeNode*root,vector<int>&inorder,int &idx)
    {
        if(root==NULL)
        return;
        f1(root->left,inorder,idx);
        root->val=inorder[idx++];
        f1(root->right,inorder,idx);
    }
    TreeNode* convertBST(TreeNode* root) {
    vector<int> inorder;
    in(root,inorder);
    int n=inorder.size();
    for(int i=n-2;i>=0;i--)
    {
        inorder[i]+=inorder[i+1];
    }
    int idx=0;
    f1(root,inorder,idx);
    return root;
    }
};