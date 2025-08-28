class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++){
        int r = i, c = 0;
        vector<int> diag;
        while (r < n && c < n){
        diag.push_back(grid[r][c]);
        r++; 
        c++;
        }
        sort(diag.rbegin(),diag.rend());
        r = i; 
        c = 0;
        int i1=0;
        while (r < n && c < n){
        grid[r][c]=diag[i1++];
        r++; 
        c++;
        }
        }
        for (int j = 1; j < n; j++){
        int r = 0, c = j;
        vector<int> diag;
        while (r < n && c < n){
        diag.push_back(grid[r][c]);
        r++; 
        c++;
        }
        sort(diag.begin(), diag.end());
        r = 0; 
        c = j;
        int i1= 0;
        while (r<n && c<n){
        grid[r][c] = diag[i1++];
        r++; 
        c++;
        }
    }
    return grid;
    }
};   