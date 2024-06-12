class Solution {
public:

    int totalNQueens(int n) {
        return backtrack(n, 0);
    }

private:
    int backtrack(int n, int row) {
        if (row == n) {
            return 1;
        }
        
        int solutions = 0;
        for (int col = 0; col < n; ++col) {
            if (cols.find(col) != cols.end() || diagonals.find(row - col) != diagonals.end() || antiDiagonals.find(row + col) != antiDiagonals.end()) {
                continue;
            }
            
            cols.insert(col);
            diagonals.insert(row - col);
            antiDiagonals.insert(row + col);
            
            solutions += backtrack(n, row + 1);
            
            cols.erase(col);
            diagonals.erase(row - col);
            antiDiagonals.erase(row + col);
        }
        
        return solutions;
    }
    
    unordered_set<int> cols;
    unordered_set<int> diagonals;
    unordered_set<int> antiDiagonals;
};
    
