#define ll long long 
class Solution {
public:
    char kthCharacter(ll k, vector<int>& op)
    {
       if(k==1)
       {
         return 'a';
       }
       int n=op.size();
       ll len=1;
       ll k1=-1;
       int op1;
       for(int i=0;i<n;i++)
       {
          len*=2;
          if(len>=k)
          {
             op1=op[i];
             k1 = k-len/2;
             break;
          }
       }
       char ch=kthCharacter(k1,op);
       if(op1==0)
       {
        return ch;
       }
       return ch=='z' ? 'a' : ch+1;
       
    }
};