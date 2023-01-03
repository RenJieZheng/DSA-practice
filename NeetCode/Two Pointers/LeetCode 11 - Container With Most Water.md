[Link to problem](https://leetcode.com/problems/container-with-most-water/)

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0;
        int rp = height.size() - 1;
        int res = 0;
        while (lp < rp) {
            res = max(min(height[lp], height[rp]) * (rp - lp), res);
            if (height[lp] > height[rp]) rp--;
            else lp++;
        }
        return res;
    }
};
```

- O(n) Time
- O(1) Space