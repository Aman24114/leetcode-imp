class Solution {
public:
    int possibleStringCount(string w) {
    int n = w.length();
    int cnt = n;
    for (int i = 1; i < n; i++)
    {
        if (w[i] != w[i - 1])
        {
            cnt--;
        }
    }
    return cnt;    
    }
};