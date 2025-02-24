class Solution {
public:
    int n;
    TreeNode* f(const string &t, int &i,int d)
    {
        if(i>=n)
        return NULL;
        int j=i;
        while(j<n && t[j]=='-')
        {
            j++;
        }
        int d1=j-i;
        if(d!=d1)
        {
            return NULL;
        }
        i+=d1;
        int val=0;
        while(i<t.length() && isdigit(t[i])) // 55
        {
            val= val*10 + (t[i]-'0');
            i++;
        }
        TreeNode* root=new TreeNode(val);
        root->left=f(t,i,d+1);
        root->right=f(t,i,d+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string t) 
    {
     n=t.length();
    int i=0;
    return f(t,i,0);
    }
};