class Solution {
public:
    int minimumBoxes(vector<int>& a, vector<int>& c) {
    int sum=0;
    for(auto it:a)
    {
        sum+=it;
    }  
    sort(c.rbegin(),c.rend());
    int ans=0;
    for(auto it:c)
    {
        sum-=it;
        ans+=1;
        if(sum<=0)
        break;
    }
    return ans;
    }
};