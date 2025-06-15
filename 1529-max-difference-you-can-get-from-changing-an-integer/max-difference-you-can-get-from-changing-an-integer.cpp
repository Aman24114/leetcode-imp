
class Solution {
public:
    int maxDiff(int num)
    {
        string s1=to_string(num);
        string s2=s1;
        int idx=s1.find_first_not_of('9');
        if(idx!=string::npos)
        {
            char ch=s1[idx];
            replace(begin(s1),end(s1),ch,'9');
        }
        for(int i=0;i<s2.length();i++)
        {
            char ch=s2[i];
            if(i==0)
            {
                if(ch!='1')
                {
                    replace(begin(s2),end(s2),ch,'1');
                    break;
                }
            }
                else if(ch!='0' && ch!=s2[0])
                {
                    replace(begin(s2),end(s2),ch,'0');
                    break;
                }
            }
        return stoi(s1)-stoi(s2);
    }

};