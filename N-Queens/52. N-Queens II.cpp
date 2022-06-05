// 52. N-Queens II
/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:
Input: n = 1
Output: 1
 
Constraints:
1 <= n <= 9
*/

class Solution {
public:
    vector<vector<string> > sols;
    vector<vector<string>> solveNQueens(int n) {    
	    vector<string> board(n, string(n, '.'));
	    solve(board, 0);
	    return sols; 
    }
    bool isSafe(vector<string>& board, int row, int col) {
	    int n = size(board);
	    for(int i = 0; i < n; i++) {
		    if(board[i][col] == 'Q') return false; 
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
	  }
	    return true;
    }
     
    void solve(vector<string>& board, int row) {
	    if(row == size(board)) { 
		    sols.push_back(board);
		    return;
    	} 
	    for(int col = 0; col < size(board); col++){
		    if(isSafe(board, row, col)) {
			    board[row][col] = 'Q';    
			    solve(board, row + 1); 
			    board[row][col] = '.'; 
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string> > ans;
        ans =  solveNQueens(n);
        int m = ans.size();
        return m;
    }    
};