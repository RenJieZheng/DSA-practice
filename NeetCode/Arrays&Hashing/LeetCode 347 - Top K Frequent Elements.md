[Link to problem](https://leetcode.com/problems/top-k-frequent-elements/)

## HashMap and Sorting:

```c++
class Solution {
	// Used to sort the hashMap of count in descending order
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
	    return a.second > b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
	    // Generate the hashMap of couts
        unordered_map<int, int> count {};
        for (int &num : nums) count[num]++;

		// Sort the couts
        vector<pair<int, int>> values;
        for (auto it = count.begin(); it != count.end(); ++it) {values.push_back(*it);
        sort(values.begin(), values.end(), cmp);

		// Create the output array with k most frequent elements
        vector<int> result {};
        int i = 0;
        for (auto it = values.begin(); it != values.end() && i < k; ++it) {
            result.push_back(it->first);
            ++i;
        }
        return result;
    }
};
```

- O(nlogn) Time
- O(n) Space

## Bucketsort:

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create the hashMap of counts
        unordered_map<int, int> count {};
        for (int &num : nums) count[num]++;

        // Perform the bucket sort
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &elem : count) bucket[elem.second].push_back(elem.first);

        // Create the output array
        vector<int> result {};
        int i = 0;
        for (auto elem = bucket.rbegin(); elem != bucket.rend() && i < k; ++elem) {
            for (auto &num : *elem) {
                result.push_back(num);
                ++i;
                if (i >= k) break;
            }
        }
        return result;
    }
};
```

- O(n) Time and Space

## Heap:

```c++

```

## Quickselect (Hoare's selection algorithm):