class Solution {
public:
    int minMaxDifference(int num)
    {
      string s=to_string(num);
      int n=s.size();
      string s1=s;
      char c1;
      int maxi=0,mini=0;
      for(int i=0;i<n;i++)
      {
         if(s[i]!='9')
         {
            c1=s[i];
            maxi=i;
            break;
         }
      }
      for(int i=0;i<n;i++)
      {
         if(s[i]==c1)
         {
            s[i]='9';
         }
      }
      char c2;
      for(int i=0;i<n;i++)
      {
         if(s1[i]!='0')
         {
            c2=s1[i];
            mini=i;
            break;
         }
      }
      for(int i=0;i<n;i++)
      {
         if(s1[i]==c2)
         {
            s1[i]='0';
         }
      }
      int n1=stoi(s);
      int n2=stoi(s1);
      return n1-n2;
    }
};