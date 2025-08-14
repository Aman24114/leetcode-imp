class Solution {
public:
    string largestGoodInteger(string num) {
    string ans="",temp="";
    int n=num.length();
    for(int i=0;i<n-2;i++)
    {
        if(num[i]==num[i+1]&& num[i]==num[i+2])
       { 
            temp=num.substr(i,3);
            if(temp>ans)
            {
                ans=temp;
            }
       }
    }
    return ans;
    }
};