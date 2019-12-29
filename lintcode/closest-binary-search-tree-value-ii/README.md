[https://www.lintcode.com/problem/closest-binary-search-tree-value-ii/](https://www.lintcode.com/problem/closest-binary-search-tree-value-ii/)

Given a non-empty binary search tree and a target value, find `k` values in the BST that are closest to the target.

**Example 1:**
```
 Input:
 {1}
 0.000000
 1
 Output:
 [1]
 Explanation：
 Binary tree {1},  denote the following structure:
 1
```

**Example 2:**
```
 Input:
 {3,1,4,#,2}
 0.275000
 2
 Output:
 [1,2]
 Explanation：
 Binary tree {3,1,4,#,2},  denote the following structure:
   3
  /  \
 1    4
  \
   2
```

**Notice:**
- Given target value is a floating point.
- You may assume `k` is always valid, that is: `k ≤ total` nodes.
- You are guaranteed to have only one `unique` set of k values in the BST that are closest to the target.
