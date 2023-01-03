[Link to problem](https://leetcode.com/problems/valid-palindrome/)

```c++
class Solution {
public:
    bool isPalindrome(string s) {
        int leftP = 0;
        int rightP = s.size() - 1;
        while (rightP > leftP) {
            while (!isalnum(s[rightP]) && rightP > leftP) rightP--;
            while (!isalnum(s[leftP]) && rightP > leftP) leftP++; 
            if (tolower(s[rightP]) != tolower(s[leftP])) return false;
            rightP--;
            leftP++;
        }
        return true;
    }
};
```

- O(n) Time
- O(1) Space