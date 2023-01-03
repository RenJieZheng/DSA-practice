[Link to problem](https://leetcode.com/problems/longest-repeating-character-replacement/description/)

```c++
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> seen {};
        int lp = 0;
        int rp = 0;
        int maxFreq = 0;
        int result = 0;
        while (rp < s.size()) {
            seen[s[rp]]++;
            maxFreq = max(maxFreq, seen[s[rp]]);
            if (rp - lp + 1 - maxFreq > k) {
                seen[s[lp]]--;
                lp++;
            }
            result = max(result, rp - lp + 1);
            rp++;
        }
        return result;
    }
};
```

- O(n) Time
- O(n) Space (O(1) if the alphabet is a constant size)