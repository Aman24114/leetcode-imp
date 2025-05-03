class Solution {
public:
    string pushDominoes(string dom)
    {
     dom=dom+'R';
     char l='L';
     int li=-1;
     int n=dom.size();
     for(int i=0;i<n;i++)
     {
        if(dom[i]=='L')
        {
            if(l=='R')
            {
                int left=li+1;
                int right=i-1;
                while(left<right)
                {
                    dom[left++]='R';
                    dom[right--]='L';
                }
            }
            else if(l=='L')
            {
                for(int j=li+1;j<i;j++)
                {
                  dom[j]='L';  
                }
            }
            l='L';
            li=i;
        }
            else if(dom[i]=='R')
            {
                if(l=='R')
                {
                    for(int j=li+1;j<i;j++)
                    {
                        dom[j]='R';
                    }
                }
            l='R';
            li=i;
            }
        }
        return dom.substr(0,n-1);
     }
};