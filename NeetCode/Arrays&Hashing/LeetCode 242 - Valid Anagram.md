[Link to problem](https://leetcode.com/problems/valid-anagram/)

## Sorting:

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return (s == t);
    }
};
```

- O(nlogn + mlogm)  Time
- O(1) Space (Depends on the sorting algorithm)

## HashMap:

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if (slen != tlen) return false;
  
        int count[256] = {};
        for (int i = 0; i < slen; ++i) {
            count[s[i]]++;
        }

        for (int i = 0; i < tlen; ++i) {
            if (count[t[i]] <= 0) return false;
            else count[t[i]]--;
        }
        
        return true;
    }
};
```

- O(n + m) Time
- O(n + m) Space