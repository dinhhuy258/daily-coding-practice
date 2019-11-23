[https://www.lintcode.com/problem/alien-dictionary/](https://www.lintcode.com/problem/alien-dictionary/)

There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of **non-empty** words from the dictionary, where words are **sorted lexicographically by the rules of this new language**. Derive the order of letters in this language.

**Example 1:**
```
 Input：["wrt","wrf","er","ett","rftt"]
 Output："wertf"
 Explanation：
 from "wrt"and"wrf" ,we can get 't'<'f'
 from "wrt"and"er" ,we can get 'w'<'e'
 from "er"and"ett" ,we can get 'r'<'t'
 from "ett"and"rftt" ,we can get 'e'<'r'
 So return "wertf"
```

**Example 2:**
```
 Input：["z","x"]
 Output："zx"
 Explanation：
 from "z" and "x"，we can get 'z' < 'x'
 So return "zx"
```

**Note:** 

1. You may assume all letters are in lowercase.
2. You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
3. If the order is invalid, return an empty string.
4. There may be multiple valid order of letters, return the smallest in normal lexicographical order.