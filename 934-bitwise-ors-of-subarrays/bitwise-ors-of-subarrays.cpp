class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
    set<int>res;
    set<int>curr;
    for(int x:arr)
    {
        set<int>next;
        next.insert(x);
        for(int y:curr)
        {
            next.insert(x|y);
        }
        res.insert(next.begin(),next.end());
        curr=next;
    }
    return res.size();
    }
};