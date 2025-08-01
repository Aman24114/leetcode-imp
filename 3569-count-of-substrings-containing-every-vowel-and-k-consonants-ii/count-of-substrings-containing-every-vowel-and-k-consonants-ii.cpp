#define ll long long
class Solution {
public:
    bool isvowel(char &ch)
    {
        return (ch=='a'|| ch=='e' || ch=='i'|| ch=='o'||ch=='u');
    }
    ll countOfSubstrings(string word, int k) {
    unordered_map<char,int>mp;
    int n=word.length();
    vector<int>nextcon(n);
    int lastidx=n;
    for(int i=n-1;i>=0;i--)
    {
        nextcon[i]=lastidx;
        if(!isvowel(word[i]))
        {
            lastidx=i;
        }
    }
    int i=0;
    int j=0;
    ll cnt=0;
    int cons=0;
    while(j<n)
    {
        char ch=word[j];
        if(isvowel(ch))
        {
            mp[ch]++;
        }
        else
        {
           cons++; 
        }
        while(i<n && cons>k)
        {
           char ch = word[i];
           if(isvowel(ch))
           {
             mp[ch]--;
             if(mp[ch]==0)
             {
                mp.erase(ch);
             }
           }
            else
            {
                cons--;
            }
           i++; 
        }
        while(i<n && mp.size()==5 && cons==k)
        {
           int idx=nextcon[j];
           cnt+=idx-j;
           char ch=word[i];
           if(isvowel(ch))
           {
             mp[ch]--;
             if(mp[ch]==0)
             {
                mp.erase(ch);
             }
           }
           else
           {
             cons--;
           }
           i++;
        } 
       j++;
    }  
    return cnt;
    }
};