class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int time=0;
    int g=0,m=0,p=0;
    for(int i=0;i<garbage.size();i++)
    {
      for(auto it:garbage[i])
      {
        if(it=='M') m=i;
        else if(it=='P') p=i;
        else  g=i;
        time++;
      }   
    }
    int sum=0;
    for(int i=0;i<travel.size();i++)
    {
        sum+=travel[i];
        if (m==i+1)
        time+=sum;
        if (p==i+1)
        time+=sum;
        if (g==i+1)
        time+=sum;
    }
    return time;
    }
};