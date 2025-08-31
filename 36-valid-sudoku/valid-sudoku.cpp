class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Row & column check
        for(int i=0; i<9; i++){
            unordered_set<char> row, col;
            for(int j=0; j<9; j++){
                // row check
                if(board[i][j] != '.'){
                    if(row.count(board[i][j])) return false;
                    row.insert(board[i][j]);
                }
                // col check
                if(board[j][i] != '.'){
                    if(col.count(board[j][i])) return false;
                    col.insert(board[j][i]);
                }
            }
        }

        // 3x3 subgrid check
        for(int blockRow=0; blockRow<9; blockRow+=3){
            for(int blockCol=0; blockCol<9; blockCol+=3){
                unordered_set<char> subgrid;
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        char ch = board[blockRow+i][blockCol+j];
                        if(ch != '.'){
                            if(subgrid.count(ch)) return false;
                            subgrid.insert(ch);
                        }
                    }
                }
            }
        }

        return true;
    }
};
