class Solution {
public:  
    bool isValidSudoku(vector<vector<char>>& board) {
    set<char>rows[9];
    set<char>cols[9];
    set<char>boxes[9]; 
    for(int r=0;r<9;r++)
    {
        for(int c=0;c<9;c++)
        {
            if(board[r][c]=='.')
            {
                continue;
            }
            char val=board[r][c];
            int boxindex=(r/3)*3+(c/3);
            if(rows[r].count(val) || cols[c].count(val) || boxes[boxindex].count(val))
            return false;
            rows[r].insert(val);
            cols[c].insert(val);
            boxes[boxindex].insert(val);
        }
    } 
    return true;       
    }
};