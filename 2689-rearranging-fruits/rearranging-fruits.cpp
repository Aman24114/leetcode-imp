#define ll long long 
class Solution {
public:
int mini=INT_MAX;
map<int,int>mp;
ll minCost(vector<int>& basket1, vector<int>& basket2) {
for(auto it:basket1)
{
    mp[it]++;
    mini=min(mini,it);
}
for(auto it:basket2)
{
    mp[it]--;
    mini=min(mini,it);
}
vector<int>finalist;
for(auto it:mp)
{
    int cost=it.first;
    int count=it.second;
    if(count==0)
    {
        continue;
    }
    if(count%2!=0)
    {
        return -1;
    }
    for(int c=1;c<=abs(count/2);c++)
    {
       finalist.push_back(cost);
    }
}
sort(finalist.begin(),finalist.end());
ll result=0;
for(int i=0;i<finalist.size()/2;i++)
{
    result+=min(finalist[i],mini*2);
}
return result;
}
};