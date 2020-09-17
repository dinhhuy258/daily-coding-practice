class Solution {
public:
    bool isRobotBounded(string instructions) {
        std::vector<int> finalVector = {0, 0};
        std::vector<int> direction = {0, 1};

        for (auto& instruction: instructions) {
            switch(instruction) {
                case 'G':
                    finalVector[0] += direction[0];
                    finalVector[1] += direction[1];
                    break;
                case 'L':
                    std::swap(direction[0], direction[1]);
                    direction[0] *= -1;
                    break;
                case 'R':
                    std::swap(direction[0], direction[1]);
                    direction[1] *= -1;
                    break;
            }
        }

        return (finalVector[0] == 0 && finalVector[1] == 0) || (direction[0] != 0 || direction[1] != 1);
    }
};

