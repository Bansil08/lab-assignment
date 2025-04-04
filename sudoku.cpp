class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& grid) {
        int size = 9;

        for(int row = 0; row < size; row++) {
            vector<int> rowCheck(10, 0), colCheck(10, 0);
            for(int col = 0; col < size; col++) {
                if(grid[row][col] == '.') continue;
                if(rowCheck[grid[row][col] - '0'] == 0) {
                    rowCheck[grid[row][col] - '0'] = 1;
                }
                else {
                    return false;
                }
            }
            for(int col = 0; col < size; col++) {
                if(grid[col][row] == '.') continue;
                if(colCheck[grid[col][row] - '0'] == 0) {
                    colCheck[grid[col][row] - '0'] = 1;
                }
                else {
                    return false;
                }
            }
        }

        for(int row = 0; row < size; row += 3) {
            for(int col = 0; col < size; col += 3) {
                vector<int> boxCheck(size + 1, 0);
                for(int dx = 0; dx < 3; dx++) {
                    for(int dy = 0; dy < 3; dy++) {
                        if(grid[row + dx][col + dy] == '.') continue;

                        if(boxCheck[grid[row + dx][col + dy] - '0'] == 0) {
                            boxCheck[grid[row + dx][col + dy] - '0'] = 1;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
