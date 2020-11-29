class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) {
            return true;
        }
        auto size = arr.size();
        std::queue<int> queue;
        std::vector<bool> visited(size, false);
        queue.push(start);
        visited[start] = true;
        while(!queue.empty()) {
            auto index = queue.front();
            queue.pop();
            if (index - arr[index] >= 0 && !visited[index - arr[index]]) {
                visited[index - arr[index]] = true;
                if (arr[index - arr[index]] == 0) {
                    return true;
                }
                queue.push(index - arr[index]);
            }
            if (index + arr[index] < size && !visited[index + arr[index]]) {
                visited[index + arr[index]] = true;
                if (arr[index + arr[index]] == 0) {
                    return true;
                }
                queue.push(index + arr[index]);
            }
        }

        return false;
    }
};

