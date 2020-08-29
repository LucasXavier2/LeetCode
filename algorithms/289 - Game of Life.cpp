//Description of the problem - https://leetcode.com/problems/game-of-life/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int numRows = board.size();
        int numColumns = board[0].size();
        vector<vector<int>> newBoard(numRows, vector<int>(numColumns));
        
        for (int row = 0; row < numRows; row++) {
            for (int column = 0; column < numColumns; column++) {
                int sum = 0;

                if (row - 1 >= 0) {
                    sum += board[row-1][column];
                    if (column - 1 >= 0) sum += board[row-1][column-1];
                    if (column + 1 < numColumns) sum += board[row-1][column+1];    
                }
                if (row + 1 < numRows) {
                    sum += board[row+1][column];
                    if (column - 1 >= 0) sum += board[row+1][column-1];
                    if (column + 1 < numColumns) sum += board[row+1][column+1];    
                }
                
                if (column + 1 < numColumns) sum += board[row][column+1];
                if (column - 1 >= 0) sum += board[row][column-1];
                
                if (sum < 2 || sum > 3) newBoard[row][column] = 0;
                else if (sum == 3) newBoard[row][column] = 1;
                else if (sum == 2 && board[row][column] == 1) newBoard[row][column] = 1;
                else newBoard[row][column] = 0;
                    
            }
        }
        
        board = newBoard;
    }
};