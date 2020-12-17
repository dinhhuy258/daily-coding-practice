class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        int n = A.size();
        std::unordered_map<int, int> map;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++map[A[i] + B[j]];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = C[i] + D[j];
                ans += map[-sum];
            }
        }

        return ans;
    }
};

