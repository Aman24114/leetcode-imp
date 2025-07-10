#define ll long long 
class Solution {
public:
    ll minimumOperations(vector<int>& nums, vector<int>& target) {
    int n=nums.size();
    ll result=0;
    vector<int>dif(n,0);
    for(int i=0;i<n;i++)
    {
        dif[i]=target[i]-nums[i];
    } 
    int curr=0;
    int prev=0;
    for(int i=0;i<n;i++)
    {
        curr=dif[i];
        if((curr>0 && prev<0)||(curr<0 && prev>0))
        {
            result+=abs(curr);
        }
        else if(abs(curr)>abs(prev))
        {
            result+=abs(curr-prev);
        }
        prev=curr;
    }
    return result;
    }
};