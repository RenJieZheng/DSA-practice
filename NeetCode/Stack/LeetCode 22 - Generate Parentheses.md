[Link to problem](https://leetcode.com/problems/generate-parentheses/)

```c++
class Solution {
    vector<string> result;
    void recursiveGenerate(int n, int open, int close, string soFar) {
        if (open == n && close == n) result.push_back(soFar);
        if (open < n) recursiveGenerate(n, open + 1, close, soFar + "(");
        if (close < open) recursiveGenerate(n, open, close + 1, soFar + ")");
    }
public:
    vector<string> generateParenthesis(int n) {
        if (n != 0) recursiveGenerate(n, 0, 0, "");
        return result;
    }
};
```

- O(2^n) Time
- O(n) Space