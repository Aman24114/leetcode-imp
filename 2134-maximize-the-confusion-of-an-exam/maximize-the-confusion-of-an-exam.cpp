// contigous hai to sw socho 
class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
    int n=ans.length();
    int result=0;
    // f-t case
    int i=0,j=0;
    int fcnt=0; 
    while(j<n)
    {
     if(ans[j]=='F')
     {
        fcnt++;
     }
     while(fcnt>k)
     {
        if(ans[i]=='F')
        {
            fcnt--;
        }
        i++;
     }
     result=max(result,j-i+1);
     j++;
    }
    // t-f case 
    int i1=0,j1=0;
    int tcnt=0; 
    while(j1<n)
    {
     if(ans[j1]=='T')
     {
        tcnt++;
     }
     while(tcnt>k)
     {
        if(ans[i1]=='T')
        {
            tcnt--;
        }
        i1++;
     }
     result=max(result,j1-i1+1);
     j1++;
    }
    return result;
    }
};