class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
    int n=tokens.size();
    int i=0,j=n-1;
    int score=0,maxscore=0;
    sort(tokens.begin(),tokens.end());
    while(i<=j)
    {
        if(tokens[i]<=power){
        score++;
        power-=tokens[i];
        maxscore=max(maxscore,score);
        i++;
        }
        else if(score>0){
        power+=tokens[j];
        score--;
        j--;
        }
        else{
        break;
        }
    }   
    return maxscore;
    }
};