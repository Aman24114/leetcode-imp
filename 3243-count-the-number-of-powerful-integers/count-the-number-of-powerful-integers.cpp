#define ll long long 
class Solution {
public:
    ll f(string &str,string& insufix,int lim)
    {
        if(str.length()<insufix.length())
        {
            return 0;
        }
        ll cnt=0;
        string rems=str.substr(str.length()-insufix.length());
        int reml= str.length()-insufix.length();
        for(int i=0;i<reml;i++)
        {
            int digit=str[i]-'0';
            if(digit<=lim)
            {
                cnt+=digit*pow(lim+1,reml-i-1); // valid cnt nikalne ke liye 
            }
            else
            {
                cnt+=pow(lim+1,reml-i);
                 return cnt;
            } 
        }
        cnt += stoll(rems) >= stoll(insufix) ? 1 : 0; // edge case
        return cnt;
    }
    ll numberOfPowerfulInt(ll start, ll fin, int lim, string s) 
    {
        string startstr = to_string(start-1);
        string finstr = to_string(fin);
        return f(finstr,s,lim)-f(startstr,s,lim);
    }
};