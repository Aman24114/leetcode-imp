#define ll long long 
class Solution {
public:
    ll minimumDifference(vector<int>& nums) {
        int n = nums.size()/3;
        ll ans = LONG_MAX;
        ll lsum=0, rsum=0;
        priority_queue<int>pq;
        priority_queue<int, vector<int>, greater<>> pq1;
        vector<ll>mlsum(nums.size());
        for (int i=0;i<2*n;++i)
        {
            pq.push(nums[i]);
            lsum += nums[i];
            if (pq.size()>n)
            {
                lsum-=pq.top();
                pq.pop();
            }
            if (pq.size()==n)
            mlsum[i]=lsum;
        }

        for (int i=nums.size()-1;i>=n;i--)
        {
            pq1.push(nums[i]);
            rsum+=nums[i];
            if (pq1.size()>n)
            {
                rsum-=pq1.top();
                pq1.pop();
            }
            if (pq1.size()==n)
            ans=min(ans,mlsum[i-1]-rsum);
        }
        return ans;
    }
};