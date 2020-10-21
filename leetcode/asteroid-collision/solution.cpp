class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::deque<int> queue;
        std::vector<int> result;
        for (auto &asteroid: asteroids) {
            if (asteroid < 0 && queue.empty()) {
                result.push_back(asteroid);
                continue;
            }
            if (asteroid > 0 && (queue.empty() || queue.back() > 0)) {
                queue.push_back(asteroid);
                continue;
            }

            bool isAsteroidDestroyed = false;
            while (!queue.empty() && !isAsteroidDestroyed) {
                if (std::abs(asteroid) > queue.back()) {
                    queue.pop_back();
                }
                else if (std::abs(asteroid) == queue.back()) {
                    queue.pop_back();
                    isAsteroidDestroyed = true;
                }
                else {
                    isAsteroidDestroyed = true;
                }
            }
            if (!isAsteroidDestroyed && asteroid > 0) {
                queue.push_back(asteroid);
            }
            else if (!isAsteroidDestroyed) {
                result.push_back(asteroid);
            }
        }
        while (!queue.empty()) {
            result.push_back(queue.front());
            queue.pop_front();
        }

        return result;
    }
};

