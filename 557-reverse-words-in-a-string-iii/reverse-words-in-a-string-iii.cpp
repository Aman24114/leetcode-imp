class Solution {
public:
    string reverseWords(string s) {
    stringstream ss(s);
    string temp,ans;
    int n=s.length();
    while(ss>>temp)
    {
        reverse(temp.begin(),temp.end());
        ans+=(temp+" ");
    }
    return ans.substr(0,ans.size()-1);
    } 
};