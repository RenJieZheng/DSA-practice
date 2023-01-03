[Link to problem](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen {};
        int result = 0;
        int lp = 0;
        int rp = 0;
        while (rp < s.size()) {
            while (seen.count(s[rp])) seen.erase(s[lp++]);
            seen.insert(s[rp++]);
            result = max(result, rp - lp);
        }
        return result;
    }
};
```

- O(n) Time
- O(n) Space