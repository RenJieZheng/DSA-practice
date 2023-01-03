[Link to problem](https://leetcode.com/problems/valid-parentheses/)

```c++
class Solution {
    bool isOpen(char ch) { return (ch == '(' || ch == '{' || ch == '['); }
public:
    bool isValid(string s) {
        stack<char> open {};
        for (char ch : s) {
            if (isOpen(ch)) open.emplace(ch);
            else if (ch == ')') {
                if (open.empty() || open.top() != '(') return false;
                else open.pop();
            } else if (ch == '}') {
                if (open.empty() || open.top() != '{') return false;
                else open.pop();
            } else if (ch == ']') {
                if (open.empty() || open.top() != '[') return false;
                else open.pop();
            }
        }
        return open.empty();
    }
};
```

- O(n) Time
- O(n) Space