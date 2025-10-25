class Solution {
public:
    int totalMoney(int n) {
    int sov=0,cnt=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt==7)
        {
            sov=floor(i/7)+1;
            cnt=0;
        }
        else 
        {
            sov++;
        }
        sum+=sov;
        cnt++;
    }   
    return sum;
    }
};