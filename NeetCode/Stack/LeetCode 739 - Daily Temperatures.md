[Link to problem](https://leetcode.com/problems/daily-temperatures/)

## Brute Force (Not Accepted):
```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result{};
        for (int i = 0; i < temperatures.size() - 1; ++i) {
            int j = i + 1;
            for (; j < temperatures.size(); j++) {
	            if (temperatures[j] > temperatures[i]) break;
	        }
            if (j == temperatures.size()) result.push_back(0);
            else result.push_back(j - i);
        }
        result.push_back(0);
        return result;
    }
};
```

- O(n^2) Time
- O(n) Space

## Stack:

```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> temps;
        vector<int> result(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!temps.empty() && temperatures[i] > temps.top().first) {
                result[temps.top().second] = i - temps.top().second;
                temps.pop();
            }
            temps.push({temperatures[i], i});
        }
        return result;
    }
};
```

- O(n) Time
- O(n) Space