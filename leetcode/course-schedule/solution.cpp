class Solution { 
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> courses;
        std::vector<int> inDegree(numCourses, 0);
        std::vector<bool> visited(numCourses, false);
        std::queue<int> queue;
        int count = 0;
        for (int i = 0; i < prerequisites.size(); ++i) {
            ++inDegree[prerequisites[i][0]];
            if (courses.find(prerequisites[i][1]) == courses.end()) {
                courses[prerequisites[i][1]] = { prerequisites[i][0] };
            }
            else {
                courses[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
        }
        
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                queue.push(i);
                visited[i] = true;
            }
        }
                
        while(!queue.empty()) {
            int course = queue.front();
            queue.pop();
            ++count;
            auto& neighbors = courses[course];
            for (auto& neighbor: neighbors) {
                if (visited[neighbor]) {
                    continue;
                }
                --inDegree[neighbor];
                if (inDegree[neighbor] == 0) {
                    queue.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        } 
        
        return count == numCourses;
    }
};
