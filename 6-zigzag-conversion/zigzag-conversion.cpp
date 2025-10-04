class Solution {
public:
    string convert(string s, int r) {
    if(r==1 || s.size()<=r)
    return s;
    vector<string>matrix(r);
    int i=0,n=s.size(),index=0;
    bool b=true;
    while(i<n)
    {
        matrix[index].push_back(s[i]);
        if(index==r-1)
        b=false;
        if(index==0)
        b=true;
        if(b)
        index++;
        else 
        index--;
        i++;
    }    
    string result;
    for(auto it:matrix)
    {
        result+=it;
    }
    return result;
    }
};