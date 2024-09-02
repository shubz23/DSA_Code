class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>> result;  
        vector<int> board(n);  
        solve(0, board, result, n);
        return result;
    }

private:
    bool isSafe(int col, vector<int>& board) {
        for (int i = 0; i < col; ++i) {
            
        
            if (board[i] == board[col] || abs(board[i] - board[col]) == abs(i - col)) {
                return false;
            }
        }
        return true;
    }

    void solve(int col, vector<int>& board, vector<vector<int>>& result, int n) {
        if (col == n) { 
            result.push_back(board);  
            return;
        }

        for (int row = 0; row < n; ++row) {
            board[col] = row + 1;  
            if (isSafe(col, board)) {  
                solve(col + 1, board, result, n); 
                
            }
        }
    }
};