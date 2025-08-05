class Solution {
public:
    bool safe(int row,int col,vector<string>board)
    {
        int row1=row;
        int col1=col;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            row--;
            col--;
        }
        col=col1,row=row1;
        while(col>=0)
        {
            if(board[row][col]=='Q')
            {
                return false;
            }
            col--;
        }
        row=row1;
        col=col1;
        while(row<board.size() && col>=0)
        {
           if(board[row][col]=='Q')
           {
             return false;
           }
           row++;
           col--;
        }
        return true;
    }
    int dfs(int col,vector<string>&board)
    {   int n=board.size();
        if(col==n)
        {
            return 1;
        }
        int cnt=0;
        for(int row=0;row<n;row++)
        {
            if(safe(row,col,board))
            {
                board[row][col]='Q';
                cnt+=dfs(col+1,board);
                board[row][col]='.'; // backtrack karte time
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++)
    {
        board[i]=s;
    }    
    return dfs(0,board);
    } 
};