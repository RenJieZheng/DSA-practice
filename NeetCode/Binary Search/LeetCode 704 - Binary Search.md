[Link to problem](https://leetcode.com/problems/binary-search/)

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lp = 0;
        int rp = nums.size() - 1;
        while (lp <= rp) {
            int idx = lp + (rp - lp) / 2;
            if (nums[idx] == target) return idx;
            else if (nums[idx] > target) rp--;
            else lp++;
        }
        return -1;
    }
};
```

- O(nlogn) Time
- O(1) Space
