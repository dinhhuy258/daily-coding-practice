[https://open.kattis.com/problems/shortestpath3](https://open.kattis.com/problems/shortestpath3)

**Input**

The input consists of several test cases. Each test case starts with a line with four non-negative integers, 1≤𝑛≤1000, 0≤𝑚≤5000, 1≤𝑞≤100 and 0≤𝑠<𝑛, separated by single spaces, where 𝑛 is the numbers of nodes in the graph, 𝑚 the number of edges, 𝑞 the number of queries and 𝑠 the index of the starting node. Nodes are numbered from 0 to 𝑛−1. Then follow 𝑚 lines, each line consisting of three (space-separated) integers 𝑢, 𝑣 and 𝑤 indicating that there is an edge from 𝑢 to 𝑣 in the graph with weight −2000≤𝑤≤2000. Then follow 𝑞 lines of queries, each consisting of a single non-negative integer, asking for the minimum distance from node 𝑠 to the node number given on the query line.

Input will be terminated by a line containing four zeros, this line should not be processed.

**Output**

For each query, output a single line containing the minimum distance from node 𝑠 to the node specified in the query, the word “Impossible” if there is no path from 𝑠 to that node, or “-Infinity” if there are arbitrarily short paths from 𝑠 to that node. Print a blank line after each test case.

**Example:**
```
 Input:

 5 4 3 0
 0 1 999
 1 2 -2
 2 1 1
 0 3 2
 1
 3
 4
 2 1 1 0
 0 1 -100
 1
 0 0 0 0

 Output:

 -Infinity
 2
 Impossible

 -100
```
