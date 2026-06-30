# Zip-Trees-Implementation
A high-performance C implementation of Zip Trees, a randomized binary search tree that mimics the structure of Treaps but uses a "zipping" and "unzipping" approach. Features logarithmic time complexity for core operations and memory-efficient node management.
##  Features

- Insert operation
- Delete operation
- Search operation
- In-order traversal
- Tree height analysis
- Performance comparison with other BST approaches


##  Concept

A Zip Tree is a randomized binary search tree where:
- Each node is assigned a random rank
- BST property is maintained on keys
- Heap property is maintained on ranks

This ensures:
- Expected **O(log n)** time complexity for operations



##  Time Complexity

| Operation | Average Case |
|----------|-------------|
| Insert   | O(log n)    |
| Delete   | O(log n)    |
| Search   | O(log n)    |



##  Tech Stack

- Language: C++
- Concepts: Data Structures, Randomized Algorithms
- STL: Used for utility functions

