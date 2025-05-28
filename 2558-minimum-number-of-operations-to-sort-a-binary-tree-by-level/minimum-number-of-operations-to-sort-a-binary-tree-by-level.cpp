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
    private:
    int f(vector<int>& arr)
    {
        map<int, int> mp;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        for(int i=0; i<temp.size(); i++)
        {
            mp[temp[i]] = i;
        }
        int ans=0;
        for(int i=0; i<arr.size();)
        {
            int ind = mp[arr[i]];
            if(ind == i)
            {
                i++;
            }
            else
            {
                int temp1 = arr[i];
                arr[i] = arr[ind];
                arr[ind] = temp1;
                ans++;
            }
        }
        return ans;
    }
    public:
    int minimumOperations(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> temp;
            while(sz--)
            {
                auto it = q.front();
                q.pop();
                temp.push_back(it->val);
                if(it->left)
                q.push(it->left);
                if(it->right) 
                q.push(it->right);
            }
            ans+=f(temp);
        }
        return ans;
    }
};