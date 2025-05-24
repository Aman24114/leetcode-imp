class Solution {
public:
    vector<int>ans;
    vector<int> findWordsContaining(vector<string>& w, char x) 
    {      
        for(int i=0;i<w.size();i++)
        {
            for(auto &ch:w[i])
            {
                if(ch==x)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
    };