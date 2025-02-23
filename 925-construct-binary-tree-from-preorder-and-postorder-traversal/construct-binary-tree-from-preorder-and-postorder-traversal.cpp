class Solution {
public:
    TreeNode* f(int pres,int poss,int pree,vector<int>pre,vector<int>pos)
    {
      if(pres>pree)
      return NULL;
      TreeNode* root= new TreeNode(pre[pres]);
      if(pres==pree)
      return root;
      int n=pre[pres+1];
      int j=poss;
      while(pos[j]!=n)
      {
        j++;
      }
      int nums = j-poss+1;
      root->left = f(pres+1,poss,pres+nums,pre,pos);
      root->right= f(pres+nums+1,j+1,pree,pre,pos);
      return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& pos) {
    int n=pre.size();
    return f(0,0,n-1,pre,pos);        
    }
};