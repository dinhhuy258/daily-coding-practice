[https://www.lintcode.com/problem/min-stack/](https://www.lintcode.com/problem/min-stack/)

Implement a stack with following functions:
* `push(val)` push val into the stack
* `pop()` pop the top element and return it
* `min()` return the smallest number in the stack

All above should be in O(1) cost.

**Example 1:**
```
 Input:
   push(1)
   pop()
   push(2)
   push(3)
   min()
   push(1)
   min()
 Output:
   1
   2
   1
```

**Example 2:**
```
 Input:
   push(1)
   min()
   push(2)
   min()
   push(3)
   min()
 Output:
   1
   1
   1
```
