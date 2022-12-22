[Link to problem](https://leetcode.com/problems/contains-duplicate/description/)

## Brute Force (Not Accepted):

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (j == i) continue;
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};
```

- O(n^2) Time
- O(1) Space

## Sorting:

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		for (int i = 0; i < len - 1; ++i) {
			if (nums[i] == nums[i + 1]) return true;
		}
		return false;
    }
};
```

- O(nlogn) Time
- O(1) Space

## HashSet:

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		std::unordered_set<int> seen;
		for (int &num : nums) {
			if (seen.count(num)) return true;
			else seen.insert(num);
		}
		return false;
    }
};
```

- O(n) Time and Space