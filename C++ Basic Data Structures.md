## Array

```c++
int nums[3]; // fixed array of size 3
int a[5] = {1, 2, 3}; // [1, 2, 3, 0, 0]
a[3] = 4; // [1, 2, 3, 4, 0]

// getting the size of an array
int len = sizeof(a);
int len2 = std::size(a);
```

## [Vector](https://en.cppreference.com/w/cpp/container/vector) 

```c++
std::vector<int> nums{1, 2, 3, 4, 5};
nums.emplace_back(4);
nums.pop_back();
nums.size();
```

## Linked List

```c++
// No built in linked list
struct LinkedListNode {
	int val;
	LinkedListNode* next;
}
```

## [Stack](https://en.cppreference.com/w/cpp/container/stack)

```c++
std::stack<int> c1;
c1.push(5); // O9
c1.pop();
c1.size();
c1.top();
```

## [Queue](https://en.cppreference.com/w/cpp/container/deque)

```c++
std::deque<int> nums;
nums.push_back(1);
nums.push_front(0);
nums.pop_front();
nums.pop_back();
nums.size();
nums.front();
nums.back();
```

## [Hash Table](https://en.cppreference.com/w/cpp/container/unordered_map)

```c++

```

## Hash Set

## Tree 

## Pair