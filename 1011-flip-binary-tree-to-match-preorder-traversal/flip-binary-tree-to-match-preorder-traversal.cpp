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
    vector<int>ans;
    bool f(TreeNode* root,vector<int>&v,int &idx)
    {
        if(!root)
        return true;
        if(root->val !=v[idx])
        return false;
        idx++;
        bool b = f(root->left,v,idx) && f(root->right,v,idx);
        if(b)
        return true;
        if(root->left)
        {
            ans.push_back(root->val);
        }
        return f(root->right,v,idx) && f(root->left,v,idx);// just flip the function call to flip the nodes 
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v)
    {
       ans.clear();
       int idx=0;
       bool b1=f(root,v,idx);
       if(!b1)
       return {-1};
       return ans;    
    }
};