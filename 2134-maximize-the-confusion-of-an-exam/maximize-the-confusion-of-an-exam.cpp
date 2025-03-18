class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
    int result=0;
    int i=0;
    int j=0;
    unordered_map<char,int>mp;
    while(j<ans.length())
    {
        mp[ans[j]]++;
        while(min(mp['T'],mp['F'])>k) 
        {
            mp[ans[i]]--;
            i++;
        }
        result=max(result,j-i+1);
        j++;
    }    
    return result;
    }
};