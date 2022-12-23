[Link to problem](https://leetcode.com/problems/product-of-array-except-self/)

## Solution

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);

        // left side producs
        result[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            result[i] = nums[i - 1] * result[i - 1];
        }

        // right side producs
        int rightProd = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            rightProd *=  nums[i + 1];
            result[i] *= rightProd;
        }
        return result;
    }
};
```

- O(n) Time
- O(n) Space (O(1) according to leetcodes specification)