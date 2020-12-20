class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.size();
        long decodedLength = 0;
        // Calculate the final decoded length
        for (int i = 0; i < n; ++i) {
            if (S[i] >= 'a' && S[i] <= 'z') {
                ++decodedLength;
            }
            else {
                decodedLength = decodedLength * (S[i] - '0');
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            K = K % decodedLength;
            if (K == 0 && S[i] >= 'a' && S[i] <= 'z') {
                return std::string(1, S[i]);
            }
            else if (S[i] >= 'a' && S[i] <= 'z') {
                --decodedLength;
            }
            else {
                decodedLength = decodedLength / (S[i] - '0');
            }
        }

        return "";
    }
};

