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
 // creating a hashset
 // 
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d){
    unordered_map<int,TreeNode*> g;
    unordered_set<int>uc;
    for(auto it: d)
    {
        int p=it[0];
        int c=it[1];
        int il=it[2];
        TreeNode* par=g.count(p) ? g[p]:new TreeNode(p);
        TreeNode* child=g.count(c)? g[c]:new TreeNode(c);
        if(il==1)
        {
            par->left=child;
        }
        else
        {
            par->right=child;
        }
        g[p]=par;
        g[c]=child;
        uc.insert(c);
    }   
    for (auto& it:g)
    {
        if (uc.find(it.first) == uc.end())
        {
            return it.second; 
        }
    }
    return NULL; 
    }
};