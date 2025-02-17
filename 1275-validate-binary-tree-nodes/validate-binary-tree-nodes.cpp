class Solution {
private: 
bool iscycle(int node,vector<int>&lc,vector<int>&rc,vector<bool>&visited)
{
    if(node==-1) return false;
     if (visited[node]) return true;
        visited[node] = true;
    visited[node]=true;
    bool isleft= iscycle(lc[node],lc,rc,visited);
    bool isright= iscycle(rc[node],lc,rc,visited);
    return (isleft || isright);
}
public:
    bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
     unordered_map<int,int>par;
     for(int node=0;node<n;node++)
     {
        if(lc[node]!=-1)
        {
        if(par.count(lc[node])!=0)
        return false;
        par[lc[node]]=node;
        }
        if(rc[node]!=-1)
        {
            if(par.count(rc[node])!=0)
         return false;
        par[rc[node]]=node;
        }
     } 
     int root=-1;
     for(int node=0;node<n;node++)
     {  
        if(par.count(node)==0)
        {
            if(root!=-1)
            return false;
            root=node;
        }
     }  
     if(root==-1)
     return false;
     vector<bool> visited(n,false);
     if(iscycle(root,lc,rc,visited))
     return false;
     for(int node=0;node<n;node++)
     {
        if(!visited[node])
        return false;
     }
     return true;
    }
};