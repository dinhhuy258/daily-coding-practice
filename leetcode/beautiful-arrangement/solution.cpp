class Solution {
private:
    void countArrangement(int n, int pos, std::vector<bool>& visited, int& ans) {
        if (pos > n) {
            ++ans;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
                visited[i] = true;
                countArrangement(n, pos + 1, visited, ans);
                visited[i] = false;
            }
        }
    }
public:
    int countArrangement(int n) {
        int ans = 0;
        std::vector<bool> visited(n + 1, false);
        countArrangement(n, 1, visited, ans);

        return ans;
    }
};

