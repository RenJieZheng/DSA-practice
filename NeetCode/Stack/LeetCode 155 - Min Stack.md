[Link to problem](https://leetcode.com/problems/min-stack/)

```c++
class MinStack {
    int min;
    stack<pair<int, int>> s;
public:
    MinStack() {}
    ~MinStack() {}
    
    void push(int val) {
        if (s.empty()) min = val;
        s.push({val, min});
        if (val < min) min = val;
    }
    
    void pop() {
        if (s.top().first == min) min = s.top().second;
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return min;
    }
};
```

- All operations are O(1) Time
- O(n) Space