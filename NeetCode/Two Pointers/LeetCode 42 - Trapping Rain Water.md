[Link to problem](https://leetcode.com/problems/trapping-rain-water/)

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> trap(height.size(), 0);
        int lmax = 0;
        int rmax = 0;
        int result = 0;
        for (int i = 0; i < height.size(); ++i) {
            lmax = max(lmax, height[i]);
            trap[i] = lmax - height[i];
        }
        for (int i = height.size() - 1; i >= 0; --i) {
            rmax = max(rmax, height[i]);
            trap[i] = min(trap[i], rmax - height[i]);
        }
        for (int &trapped : trap) {
            result += trapped;
        }
        return result;
    }
};
```

- O(n) Time
- O(n) Space

## Constant Space Solution:

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int result = 0;
        int maxLeft = height[i];
        int maxRight = height[j];
        while (i < j) {
            if (maxLeft <= maxRight) {
	            result += maxLeft - height[i];
                i++;
                maxLeft = max(maxLeft, height[i]);
            } else {
                result += maxRight - height[j];
                j--;
                maxRight = max(maxRight, height[j]);
            }
        }
        return result;
    }
};
```

- O(n) Time
- O(1) Space