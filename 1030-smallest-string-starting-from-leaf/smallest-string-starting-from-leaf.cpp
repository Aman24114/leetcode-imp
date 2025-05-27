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
    string ans;
    void f(TreeNode* root,string temp)
    {
        if(root->left == NULL && root->right==NULL)
        {
            temp+=char('a'+root->val);
            reverse(temp.begin(),temp.end());
            if(ans=="" || temp<ans)
            {
                ans=temp;
                return ;
            }
        }
        if(root->left)
        {
            f(root->left,temp+char('a'+root->val));
        }
        if(root->right)
        {
            f(root->right,temp+char('a'+root->val));
        }
        return;
    }
    string smallestFromLeaf(TreeNode* root)
    {
      f(root,"");
      return ans;    
    }
};