class Solution {
public:
    bool closeStrings(string word1, string word2) {
    vector<int>w1(26,0);
    vector<int>w2(26,0);
    set<char>s1,s2;
    for(auto it:word1)
    {
      w1[it-'a']++;
      s1.insert(it);
    }
    for(auto it:word2)
    {
      w2[it-'a']++;
      s2.insert(it);
    }
    sort(w1.begin(),w1.end());
    sort(w2.begin(),w2.end());
    return w1==w2 && s1==s2;
    }
};