class Solution {
public:
    int maximumGain(string s, int x, int y){
    if(x<y)
    {
        swap(x,y);
        reverse(s.begin(),s.end());
    }
    int ans=0;
    stack<char>st;
    for(auto &it:s)
    {
        if(!st.empty()&& st.top()=='a' && it=='b')
        {
            st.pop();
            ans+=x;
        }
        else 
        {
            st.push(it);
        }
    }
    string s1;
    while(!st.empty())
    {
        s1+=st.top();
        st.pop();
    }
    for(auto &it:s1)
    {
        if(!st.empty()&& st.top()=='a'&& it=='b')
        {
            st.pop();
            ans+=y;
        }
        else 
        {
            st.push(it);
        }
    }
    return ans;
    }
};