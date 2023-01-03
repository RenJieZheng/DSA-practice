[Link to problem](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

```c++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> nums {};
        for (string token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                nums.push(stoi(token));
                continue;
            }

            long long int val2 = nums.top();
            nums.pop();
            long long int val1 = nums.top();
            nums.pop();
            if (token == "+") {
                nums.push(val1 + val2);
            } else if (token == "-") {
                nums.push(val1 - val2);
            } else if (token == "*") {
                nums.push(val1 * val2);
            } else if (token == "/") {
                nums.push(val1 / val2);
            }
        }
        return nums.top();
    }
};
```

- O(n) Time
- O(n) Space