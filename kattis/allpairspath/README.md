[https://open.kattis.com/problems/allpairspath](https://open.kattis.com/problems/allpairspath)

**Input**

The input consists of several test cases. Each test case starts with a line with three non-negative integers, 1≤𝑛≤150, 0≤𝑚≤5000 and 1≤𝑞≤1000, separated by single single spaces, where 𝑛 is the numbers of nodes in the graph, 𝑚 the number of edges and 𝑞 the number of queries. Nodes are numbered from 0 to 𝑛−1. Then follow 𝑚 lines, each line consisting of three (space-separated) integers 𝑢, 𝑣 and 𝑤 indicating that there is an edge from 𝑢 to 𝑣 in the graph with weight −1000≤𝑤≤1000. Then follow 𝑞 lines of queries, each consisting of two node numbers 𝑢 and 𝑣 (separated by a space), asking for the minimum distance from node 𝑢 to node 𝑣.

Input will be terminated by a line containing 0 0 0, this line should not be processed.

**Output**

For each query, output a single line containing the minimum distance from node 𝑢 to 𝑣, or the word Impossible if there is no path from 𝑢 to 𝑣, or -Infinity if there are arbitrarily short paths from 𝑢 to 𝑣. Print a blank line after each test case.

**Example:**
```
 Input:

 4 3 4
 0 1 2
 1 2 2
 3 3 1
 0 2
 1 2
 3 0
 3 3
 2 1 2
 0 1 100
 0 1
 1 0
 0 0 0

 Output:

 4
 2
 Impossible
 0

 100
 Impossible
```
