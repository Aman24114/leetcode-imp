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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>result;
    if(!root)
    return result;
    deque<TreeNode*>q;
    q.push_back(root);
    int count=0;
    while(!q.empty())
    {
        int size=q.size();
        vector<int>res;
        while(size>0)
        {
            size--;
            if(count%2==0)
            {
                TreeNode* node=q.front();
                q.pop_front();
                res.push_back(node->val);
                if(node->left)
                {
                    q.push_back(node->left);
                }
                if(node->right)
                {
                    q.push_back(node->right);
                }
            }
            else 
            {
                TreeNode* node=q.back();
                q.pop_back();
                res.push_back(node->val);
                if(node->right)
                {
                    q.push_front(node->right);
                }
                if(node->left)
                {
                    q.push_front(node->left);
                }

            }
        }
        result.push_back(res);
        count++;
    }    
    return result;
    }
};