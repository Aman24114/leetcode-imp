// odd ya even ho alice hi jeetega 
// if vowel =0 and constonant se word bnara hai tabhi bob can win 
// ek bhi vowel hua toh alice optimally khelke jeet jaayega
class Solution {
public:
    bool doesAliceWin(string s) {
    int x=0;
    for(auto it:s)
    {
       if(it=='a'|| it=='e'|| it=='i'|| it=='o'||it=='u')
       return true; 
    }   
    return false;
    }
};