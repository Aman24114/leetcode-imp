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
    int maxLevelSum(TreeNode* root) {
    map<int,int> m;// declare map
    if(!root)
    return 0;
    queue<TreeNode*> q; // declare queue
    q.push(root);
    int lvl=1;
    while(!q.empty())
    {
        int sum=0;// initialize sum count by 0 
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            TreeNode* temp=q.front();
            q.pop();
            sum+= temp->val;// add the node vL IN TE SUM
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
        }
        if(m.find(sum)==m.end())
        {
            m[sum]=lvl;
        }
        lvl++;
    }
    int max_sum=INT_MIN;
    int ans=0;
    for(auto it : m)
    {
        if(max_sum<it.first)
        {
            max_sum=it.first;
            ans=it.second;
        }
    }
    return ans;
    }
};