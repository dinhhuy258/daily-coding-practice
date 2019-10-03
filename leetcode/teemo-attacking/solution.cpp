class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int poisonedDuration = 0;
        if (timeSeries.empty()) {
            return poisonedDuration;
        }
        for (int i = 1; i < timeSeries.size(); ++i) {
            if (timeSeries[i] - timeSeries[i - 1] >= duration) {
                poisonedDuration += duration;
            }
            else {
                poisonedDuration += timeSeries[i] - timeSeries[i - 1];
            }
        }

        return poisonedDuration + duration;
    }
};