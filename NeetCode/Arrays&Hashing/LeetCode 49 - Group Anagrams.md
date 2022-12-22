[Link to problem](https://leetcode.com/problems/group-anagrams/)

## HashMap and Sorting:

```c++
class Solution {
    string getKey(string &s) { // each anagram will have a unique key when sorted
        string key = s;
        sort(key.begin(), key.end());
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups {};
        for (string &s : strs) {
            string key = getKey(s);
            groups[key].push_back(s);
        }

        vector<vector<string>> result {};
        for (auto &group : groups) {
            result.push_back(group.second);
        }
        return result;
    }
};
```

- O(m * nlogn) Time
- O(n) Space

## HashMap:

```c++
class Solution {
    string getKey(string &s) { // Key itself is a "HashMap"
        char counts[26] = {};
        for (auto &ch : s) {
            counts[ch - 'a']++;
        }
        string key = "";
        for (int count : counts) {
            key += to_string(count + '0');
        }
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups {};
        for (string &s : strs) {
            string key = getKey(s);
            groups[key].push_back(s);
        }
  
        vector<vector<string>> result {};
        for (auto &group : groups) {
            result.push_back(group.second);
        }
        return result;
    }
};
```

- O(m * n) Time
- O(n) Space