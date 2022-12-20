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
std::unordered_map<int, int> map;
map.at(key);
map[key];
map[key] = item;
map.count(key);
map.erase(key);
```

## [Hash Set](https://en.cppreference.com/w/cpp/container/unordered_set)

```c++
std::unordered_set<int> set;
set.count(item);
set.insert(item);
set.erase(item);
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

std::pair<std::string, int> task1;    // default constructor
std::pair<std::string, int> task2("write tests", 5);  // value init

task1 = std::make_pair(std::string("define specs"), 3);    // assign values to task1
task2.second = 7;      // change the second value in task2

std::cout << task1.first << " takes " << task1.second << std::endl;   // define specs takes 3
std::cout << task2.first << " takes " << task2.second << std::endl;   // write tests takes 7
```