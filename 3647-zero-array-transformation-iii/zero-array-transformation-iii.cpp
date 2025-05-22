class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries)
    {
       sort(queries.begin(),queries.end());
       int n=nums.size();
       int n1=queries.size();
       priority_queue<int>pq;
       priority_queue<int,vector<int>,greater<int>>pq1;
       int ans=0;
       int j=0;
       for(int i=0;i<n;i++)
       {
          while(j<n1 && queries[j][0]==i)
          {
            pq.push(queries[j][1]);
            j++;
          }
          nums[i]-=pq1.size();
          while(nums[i]>0 && !pq.empty() && pq.top()>=i)
          {
            pq1.push(pq.top());
            pq.pop();
            nums[i]--;
            ans++;
          }
           if(nums[i]>0)
           return -1;
           while(!pq1.empty() && pq1.top()==i)
           {
             pq1.pop();
           }
       }
       return n1-ans;
    }
};