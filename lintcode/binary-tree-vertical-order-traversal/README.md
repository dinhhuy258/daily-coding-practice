[https://www.lintcode.com/problem/binary-tree-vertical-order-traversal/](https://www.lintcode.com/problem/binary-tree-vertical-order-traversal/)

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from **left to right**.


**Example 1:**
```
 Input:  {3,9,20,#,#,15,7}
 Output: [[9],[3,15],[20],[7]]
 Explanation:
    3
   /\
  /  \
  9  20
     /\
    /  \
   15   7
```

**Example 2:**
```
 Input: {3,9,8,4,0,1,7}
 Output: [[4],[9],[3,0,1],[8],[7]]
 Explanation:
       3
      /\
     /  \
    9    8
   /\    /\
  /  \  /  \
 4   0 1    7
```
