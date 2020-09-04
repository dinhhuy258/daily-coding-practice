class Solution {
public:
    vector<int> partitionLabels(string S) {
        std::vector<int> lastSeen(26, -1);
        for (int i = 0; i < S.size(); ++i) {
            lastSeen[S[i] - 'a'] = i;
        }
        std::vector<int> result;
        int lastSeenIndex = -1;
        int firstPartitionIndex = 0;
        for (int i = 0; i < S.size(); ++i) {
            lastSeenIndex = std::max(lastSeenIndex, lastSeen[S[i] - 'a']);
            if (lastSeenIndex == i) {
                result.push_back(lastSeenIndex - firstPartitionIndex + 1);
                firstPartitionIndex = i + 1;
                lastSeenIndex = -1;
            }
        }
        return result;
    }
};

