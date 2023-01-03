[Link to problem](https://leetcode.com/problems/3sum/)

## Sorting and Two Pointers:

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result {};
        int p1 = 0;
        while (p1 < nums.size() - 2) {
            if (p1 > 0 && nums[p1] == nums[p1 - 1]) {
                p1++;
                continue;
            }

            int p2 = p1 + 1;
            int p3 = nums.size() - 1;
            while (p2 < p3) {
                if (nums[p1] + nums[p2] + nums[p3] == 0) {
                    result.push_back({nums[p1], nums[p2], nums[p3]});
                    while (p2 < p3 && nums[p3] == nums[p3 - 1]) p3--;
                    p3--;
                    while (p2 < p3 && nums[p2] == nums[p2 + 1]) p2++;
                    p2++;
                } else if (nums[p1] + nums[p2] + nums[p3] > 0) {
                    p3--;
                } else {
                    p2++;
                }
            }
            p1++;
        }
        return result;
    }
};
```

- O(n^2) Time
- O(n) Space (Depending on the sorting algorithm)