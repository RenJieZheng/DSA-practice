[Link to problem](https://leetcode.com/problems/two-sum/)

## Brute Force:

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] + nums[j] == target) {
                    return vector<int> {i, j};
                }
            }
        }
        return vector<int> {};
    }
};
```

- O(n^2) Time
- O(1) Space

## HashMap:

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (seen.count(target - nums[i])) return {seen.at(target - nums[i]), i};
            else seen.emplace(nums[i], i);
        }
        return {};
    }
};
```