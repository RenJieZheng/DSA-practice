[Link to problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = prices[0];
        int max_profit = 0;
        for (int &price : prices) {
            if (price < low) low = price;
            max_profit = max(max_profit, price - low);
        }
        return max_profit;
    }
};
```
- O(n) Time
- O(1) Space