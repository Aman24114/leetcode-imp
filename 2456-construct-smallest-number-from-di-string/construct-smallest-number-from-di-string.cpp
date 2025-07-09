class Solution {
public:
    string smallestNumber(string pattern) {
    int n=pattern.size();
    string num="";
    int cnt=1;
    stack<char>st;
    for(int i=0;i<=n;i++)
    {
        st.push(cnt+'0');
        cnt++;
        if(i==n || pattern[i]=='I')
        {
            while(!st.empty())
            {
                num+=st.top();
                st.pop();
            }
        }
    } 
    return num;  
    }
};