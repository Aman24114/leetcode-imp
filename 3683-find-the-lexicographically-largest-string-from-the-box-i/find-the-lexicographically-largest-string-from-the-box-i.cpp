class Solution {
public:
    string answerString(string w, int nf)
    {
       int n=w.length();
       if(nf==1)
       {
         return w;
       } 
       string ans="";
       int l= n-(nf-1);
       for(int i=0;i<n;i++)
       {
          int can=min(l,n-i);
          ans=max(ans,w.substr(i,can));
       }   
       return ans;
    }
};