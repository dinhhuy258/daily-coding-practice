class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        int maxScore = 0;
        int currentScore = 0;
        std::sort(tokens.begin(), tokens.end());
        int i = 0;
        int j = tokens.size() - 1;
        while (i <= j) {
            if (tokens[i] <= P) {
                P -= tokens[i++];
                ++currentScore;
                maxScore = std::max(maxScore, currentScore);
            }
            else if (currentScore >= 1) {
                --currentScore;
                P += tokens[j--];
            }
            else {
                --j;
            }
        }

        return maxScore;
    }
};

