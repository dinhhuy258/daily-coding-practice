[https://www.interviewbit.com/problems/redundant-braces/](https://www.interviewbit.com/problems/redundant-braces/)

Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.

Chech whether A has redundant braces or not.

Return 1 if A has redundant braces, else return 0.

**Example 1:**
```
 Input: A = "((a + b))"
 Output: 1
 Explanation: ((a + b)) has redundant braces so answer will be 1.
```

**Example 2:**
```
 Input: A = "(a + (a + b))"
 Output: 0
 Explanation: (a + (a + b)) doesn't have have any redundant braces so answer will be 0.
```

**Note::**

A will be always a valid expression.
