class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int lastSeatIndex = -1;
        int size = seats.size();
        int result = 0;
        for (int i = 0; i < size; ++i) {
            if (seats[i] == 1) {
                if (lastSeatIndex == -1) {
                    result = i;
                    lastSeatIndex = i;
                }
                else {
                    result = std::max(result, (i - lastSeatIndex) / 2);
                    lastSeatIndex = i;
                }
            }
        }
        return std::max(result, size - lastSeatIndex - 1);
    }
};

