[https://www.lintcode.com/problem/missing-ranges/](https://www.lintcode.com/problem/missing-ranges/)

Given a sorted integer array where **the range of elements are in the inclusive range [lower, upper]**, return its missing ranges.

**Example 1:**
```
 Input:
 nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99

 Output:
 ["2", "4->49", "51->74", "76->99"]

 Explanation:
 in range[0,99],the missing range includes:range[2,2],range[4,49],range[51,74] and range[76,99]
```

**Example 1:**
```
 Input:
 nums = [0, 1, 2, 3, 7], lower = 0 and upper = 7
 
 Output:
 ["4->6"]

 Explanation:
 in range[0,7],the missing range include range[4,6]
```
