[Link to problem](https://leetcode.com/problems/largest-rectangle-in-histogram/)

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stck;
        int result = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int idx = i;
            while (!stck.empty() && stck.top().second >= heights[i]) {
                idx = stck.top().first;
                int width = i - idx;
                int height = stck.top().second;
                stck.pop();
                result = max(result, height * width);
            } 
            stck.push({idx, heights[i]});
        }
        while (!stck.empty()) {
            int width = heights.size() - stck.top().first;
            int height = stck.top().second;
            stck.pop();
            result = max(result, height * width);
        }
        return result;;
    }
};
```

- O(n) Time and Space