// gray code- consecutive numbers differ by only one bit 
// i^(i>>1) provides gray code in one step
class Solution {
public:
    vector<int> grayCode(int n) {
    int size=1<<n;
    vector<int>ans(size);
    for(int i=0;i<size;i++)
    {
        ans[i]=i^(i>>1);
    }
    return ans;
    }
};