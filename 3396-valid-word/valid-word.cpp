class Solution {
public:
    bool isValid(string word)
    {
      int n=word.length();
      if(n<3)
      return false;
      int v=0,c=0;
      string vowel="aeiouAEIOU";
      for(auto it:word)
      {
        if(isalpha(it))
        {
            if(vowel.find(it)!=string::npos)
            {
                v++;
            }
            else 
            {
                c++;
            }
        }
        else if(!isdigit(it))
        {
            return false;
        }
      }
      return v>=1 && c>=1;
    }
};