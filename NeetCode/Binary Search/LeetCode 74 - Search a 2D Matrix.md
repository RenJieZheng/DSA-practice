[Link to problem](https://leetcode.com/problems/search-a-2d-matrix/description/)

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int lp = 0;
        int rp = r * c - 1;
        while (lp <= rp) {
            int idx = lp + (rp - lp) / 2;
            if (matrix[idx / c][idx % c] == target) return true;
            else if (matrix[idx / c][idx % c] > target) rp--;
            else lp++;
        }
        return false;
    }
};
```

- O(log(m * n)) Time
- O(1) Space