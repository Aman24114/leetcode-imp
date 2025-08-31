class Solution {
public:
    bool isvalid(vector<vector<char>>&board,int r,int c,char ch)
    {
        for(int i=0;i<9;i++)
        {
            if(board[r][i]==ch)
            return false;
            if(board[i][c]==ch)
            return false;
        }
        int boxindex=(r/3)*3;
        int boxcol=(c/3)*3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[boxindex+i][boxcol+j]==ch)
                return false;
            }
        }
        return true;
    }
    bool f(vector<vector<char>>&board)
    {
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                if(board[r][c]=='.')
                {
                    for(char ch='1';ch<='9';ch++)
                    {
                        if(isvalid(board,r,c,ch))
                        {
                            board[r][c]=ch;
                            if(f(board))
                            return true;
                            board[r][c]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
    f(board);    
    }
};