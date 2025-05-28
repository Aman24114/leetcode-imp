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
    int ans;
    void f(TreeNode* root, vector<int>&v)
    {
      if(root!=NULL)
      {
        v[root->val]++;
        if(root->left==NULL && root->right ==NULL)
        {
            int odd=0;
            for(int i=1;i<=9;i++)
            {
                if(v[i]%2!=0)
                {
                    odd++;
                }
            }
            ans+= odd <= 1;
        }
        f(root->left,v);
        f(root->right,v);
        v[root->val]--;
      }
    }
    int pseudoPalindromicPaths (TreeNode* root)
    {
        vector<int> v(10,0);
        f(root,v);
        return ans;    
    }
};