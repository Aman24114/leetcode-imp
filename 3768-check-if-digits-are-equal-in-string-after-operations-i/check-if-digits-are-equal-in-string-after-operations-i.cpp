class Solution {
public:
bool hasSameDigits(string s){
int i=0;
string s1="";
while(s.size()>2 && i<s.size()-1){
s1+=(s[i]+s[i+1])%10;
i++;
if(i==s.size()-1)
{
    s=s1;
    i=0;
    s1="";
}
}
if(s.size()==2 && s[0]==s[1])
return true;
else 
return false;
}
};