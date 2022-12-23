## Array

```c++
// Initialization
int nums[3]; 
int a[5] = {1, 2, 3}; 

// Mutating
a[3] = 4; 

// Capacity
sizeof(a);
std::size(a);
```

## [Vector](https://en.cppreference.com/w/cpp/container/vector) 

```c++
// Initialization
std::vector<int> nums;
std::vector<int> nums {1, 2, 3, 4, 5};

// Mutating
nums.emplace_back(item);
nums.push_back(item);
nums.pop_back();
nums[index] = value;

// Accessing
nums[index];
nums.at(index);
nums.front();
nums.back();

// Capacity
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
// Initialization
std::stack<int> c1;

// Mutating
c1.push(item);
c1.emplace(item);
c1.pop();

// Accesing
c1.top();

// Capacity
c1.empty();
c1.size();
```

## [Queue](https://en.cppreference.com/w/cpp/container/deque)

```c++
// Initialization
std::deque<int> nums;

// Mutating
nums.push_back(item);
nums.push_front(item);
nums.emplace_back(item);
nums.emplace_front(item);
nums.pop_front();
nums.pop_back();

// Accessing
nums.front();
nums.back();
nums[index];
nums.at(index);

// Capacity
nums.size();
nums.empty();

```

## [Hash Table](https://en.cppreference.com/w/cpp/container/unordered_map)

```c++
// Initialization
std::unordered_map<int, int> map;

// Accessing
map.at(key);
map[key];

// Mutating
map.insert({key, value});
map[key] = item;
map.erase(key);

// Locating
map.count(key);

// Capactiy
map.size();
map.empty();

```

## [Hash Set](https://en.cppreference.com/w/cpp/container/unordered_set)

```c++
std::unordered_set<int> set;
set.count(item);

// Mutating
set.insert(item);
set.erase(item);

// Locating
set.count(item);

// Capacity
set.empty();
set.size();
```

## Tree 

```c++
// No build in Tree

// Binary Tree
struct Node {
	int val;
    Node* left;
    Node* right;

    Node(T val, Node* left = nullptr, Node* right = nullptr)
        : val{val}, left{left}, right{right} {}
};

// N-ary Tree
#include <vector>

struct Node {
    int val;
    std::vector<Node*> children;

    Node(int val, std::vector<Node*> children = {})
        : val{val}, children{children} {}
};
```

## Pair

```c++
#include <utility>  // pair, make_pair
#include <string>   // string

// Initialization
std::pair<std::string, int> task1;
std::pair<std::string, int> task2(First, Second); 
task1 = std::make_pair(First, Second);

// Mutating
task2.second = 7;
```