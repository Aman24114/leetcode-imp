class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& in, vector<string>& sup) 
    {
     unordered_map<string,vector<string>>adj;
     unordered_map<string,int>ind;
     for(int i=0;i<in.size();i++)
     {
        for(auto it:in[i])
        {
            adj[it].push_back(r[i]);
            ind[r[i]]++;
        }
     }
     queue<string>q;
     for(auto it:sup)
     {
        if(ind[it]==0)
        {
            q.push(it);
        }
     }
     while(!q.empty())
     {
        string node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            ind[it]--;
            if(ind[it]==0)
            {
                q.push(it);
            }
        }
     }
     vector<string>ans;
     for(auto it:r)
     {
        if(ind[it]==0)
        {
            ans.push_back(it);
        }
     }
     return ans;
    }
};