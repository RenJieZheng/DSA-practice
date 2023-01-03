[Link to problem](https://leetcode.com/problems/longest-consecutive-sequence/)

## Sorting:

```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());
        for (int num : nums) {
            cout << num;
        }
        int maxLen = 1;
        int currLen = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] == nums[i]) continue;
            if (nums[i + 1] - nums[i] == 1) currLen++;
            else {
                if (currLen > maxLen) maxLen = currLen;
                currLen = 1;
            }
        }
        if (currLen > maxLen) maxLen = currLen;
        return maxLen;
    }
};
```

- O(nlogn) Time
- O(1) Space

## HashSet:

```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set {};
        for (int &num : nums) set.insert(num);

        int maxLen = 0;
        for (int num: nums) {
            if (set.count(num - 1)) continue;
            int currLen = 0;
            while (set.count(num++)) currLen++;
            if (currLen > maxLen) maxLen = currLen;
        }
        return maxLen;
    }
};
```

- O(n) Time
- O(n) Space

```c++

// NOT WORKING, FIGURE OUT WHY LATER
class Solution {

public:

    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> set {};

        unordered_set<int> seen {};

        for (int &num : nums) {

            set.insert(num);

        }

        int maxLen = 1;

        for (int &num: nums) {

            if (seen.count(num)) continue;

            seen.insert(num);

            int left = num - 1;

            int right = num + 1;

            int currLen = 1;

            while (true) {

                if (!(set.count(left) || set.count(right))) break;

                if (set.count(left)) {

                    seen.insert(left);

                    left--;

                    currLen++;

                }

                if (set.count(right)) {

                    seen.insert(right);

                    right--;

                    currLen++;

                }

            }

            if (currLen > maxLen) maxLen = currLen;

        }

        return maxLen;

    }

};
```