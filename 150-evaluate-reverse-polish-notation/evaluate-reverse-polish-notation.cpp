class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack<int>st;
    for(auto s:tokens)
    {
        if(s!="*"&& s!="/" && s!="+" && s!="-")
        {
            st.push(stoi(s));
            continue;
        }
        if(!st.empty())
        {
            int a=st.top();st.pop();
            int b=st.top();st.pop();
            if(s=="*")
            {
                st.push(a*b);
            }
            if(s=="/")
            {
                st.push(b/a);
            }
            else if(s=="+")
            {
                st.push(a+b);
            }
            else if(s=="-")
            {
                st.push(b-a);
            }
        }  
    }  
    int ans=st.top();
    st.pop();
    return ans;
    }
};