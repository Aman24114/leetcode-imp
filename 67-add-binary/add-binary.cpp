class Solution {
public:
    string addBinary(string a, string b) {
    if(b.size()>a.size())
    {
        swap(a,b);
    } 
    while(b.size()<a.size())
    {
        b="0"+b;
    }
    int carry=0;
    string ans="";
    for(int i=b.size()-1;i>=0;i--)
    {
        if(b[i]=='1' && a[i]=='1')
        {
            if(carry==0)
            ans="0"+ans;
            else ans="1"+ans;
            carry=1;
        }
        else if(b[i]=='0' && a[i]=='0')
        {
            if(carry==0)
            ans="0"+ans;
            else 
            {
                ans="1"+ans;
                carry=0;
            }
        }
        else if((b[i]=='1'&& a[i]=='0') ||(b[i]=='0' && a[i]=='1'))
        {
            if(carry==0)
            {
                ans="1"+ans;
            }
            else 
            {
                ans="0"+ans;
                carry=1;
            }
        }
    }
    if(carry==1)
    ans="1"+ans;
    return ans;
    }
};