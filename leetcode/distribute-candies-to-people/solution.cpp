class Solution {
public:
    std::vector<int> distributeCandies(int candies, int num_people) {
        std::vector<int> result(num_people, 0);

        int numRound = std::floor((-1 + std::sqrt(1 + 8 * (double)candies)) / 2 / num_people);
        int candiesLeft = candies;
        if (numRound != 0) {
            for (int i = 0; i < num_people; ++i) {
                auto firstRound = i + 1;
                auto lastRound = firstRound + num_people * (numRound - 1);
                result[i] = (firstRound + lastRound) * numRound / 2;
                candiesLeft -= result[i];
            }
        }

        auto numDistributedCandies = 1 + num_people * numRound;
        for (int i = 0; i < num_people; ++i) {
            result[i] += std::min(numDistributedCandies, candiesLeft);
            candiesLeft -= numDistributedCandies;
            ++numDistributedCandies;
            if (candiesLeft <= 0) {
                break;
            }
        }

        return result;
    }
};

