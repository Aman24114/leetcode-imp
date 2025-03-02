class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1, vector<vector<int>>& n2) {
    int i=0;
    int j=0;
    vector<vector<int>>ans;
    while(i<n1.size() && j<n2.size())
    {
        int d1=n1[i][0],v1=n1[i][1];
        int d2=n2[j][0],v2=n2[j][1];
        if(d1<d2)
        {
          ans.push_back({d1,v1});
          i++;
        }
        else if(d1>d2)
        {
            ans.push_back({d2,v2});
            j++;
        }
        else
        {
            ans.push_back({d2,v1+v2});
            i++,j++;
        }
    } 
    while(i<n1.size())
    {
        ans.push_back(n1[i]);
        i++;
    } 
    while(j<n2.size())
    {
        ans.push_back(n2[j]);
        j++;
    }
    return ans;
    }
};