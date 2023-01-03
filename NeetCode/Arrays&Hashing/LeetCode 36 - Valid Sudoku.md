[Link to problem](https://leetcode.com/problems/valid-sudoku/)

## HashMap:

```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {{}};
        bool column[9][9] = {{}};
        bool square[9][9] = {{}};
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '0' - 1;
                int sIdx = (i / 3) * 3 + (j / 3);

                if (row[i][num] || column[j][num] || square[sIdx][num]) return false;

                row[i][num] = true;
                column[j][num] = true;
                square[sIdx][num] = true;
            }
        }
        return true;
    }
};
```

- O(1) Time
- O(1) Space