class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> v;
        v.push_back(words[0]);
        int p = groups[0];
        for(int i=1;i<n;i++)
        {
            if(groups[i]!=p)
            {
                v.push_back(words[i]);
                p = groups[i];
            }
        }
        return v;
    }
};