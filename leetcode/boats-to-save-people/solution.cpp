class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int ans = 0;
        int i = 0;
        int j = people.size() - 1;

        while (i <= j) {
            ++ans;
            if (people[i] + people[j] <= limit) {
                ++i;
            }
            // Always carry the heaviest person
            --j;
        }

        return ans;
    }
};

