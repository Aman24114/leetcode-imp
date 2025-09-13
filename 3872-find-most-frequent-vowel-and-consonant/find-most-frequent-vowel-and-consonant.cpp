class Solution {
public:
    int maxFreqSum(string s) {
    int c1=0,c2=0;
    int freq[26];
    for(auto it:s)
    {
        freq[it-'a']++;
    }  
    for(char ch='a';ch<='z';ch++)
    {
        if(ch=='a'|| ch=='e'||ch=='i'||ch=='o'||ch=='u')
        {
            c1=max(c1,freq[ch-'a']); 
        }
        else
        {
            c2=max(c2,freq[ch-'a']);
        }
    }
    return c1+c2;
    }
};