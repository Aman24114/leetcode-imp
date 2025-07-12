class Solution {
public:
    int bestClosingTime(string customers) {
    int hour=0;
    int n=customers.size();
    int p=count(customers.begin(),customers.end(),'Y');
    int minp=p;
    for(int i=0;i<n;i++)
    {
        if(customers[i]=='Y')
        {
            p--;
        }
        else
        {
            p++;
        }
        if(p<minp)
        {
            minp=p;
            hour=i+1;
        }
    }   
    return hour;
    }
};