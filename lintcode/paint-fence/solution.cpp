class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        int totalNumberOfWays, samePosts, diffPosts = 0;
        for (int i = 0; i < n; ++i) {
            samePosts = diffPosts;
            diffPosts = i == 0 ? k : totalNumberOfWays * (k - 1);
            totalNumberOfWays = samePosts + diffPosts;
        }
        
        return totalNumberOfWays;
    }
};
