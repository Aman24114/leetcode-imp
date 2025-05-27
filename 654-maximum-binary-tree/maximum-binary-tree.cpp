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
    TreeNode* f(vector<int>&nums,int s ,int e)
    {
        if(s>e)
        return NULL;
        int p=s;
        for(int i=s+1;i<=e;i++)
        {
            if(nums[i]>nums[p])
            {
                p=i;
            }
        }
        TreeNode* root= new TreeNode(nums[p]);
        root->left=f(nums,s,p-1);
        root->right=f(nums,p+1,e);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
     return f(nums,0,nums.size()-1);
    }
};