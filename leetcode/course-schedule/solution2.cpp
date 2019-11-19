class Solution {
private:
    bool isCyclic(int course, 
                  std::unordered_map<int, std::vector<int>>& courses, 
                  std::vector<bool>& visited,
                  std::vector<bool>& inStack) {
        visited[course] = true;
        inStack[course] = true;
        auto& neighbors = courses[course];
        for (auto& neighbor: neighbors) {
            if (!visited[neighbor]) {
                if (isCyclic(neighbor, courses, visited, inStack)) {
                    return true;
                }
            }
            else if (inStack[neighbor]) {
                return true;
            }
        }
        inStack[course] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> courses;
        std::vector<bool> visited(numCourses, false);
        std::vector<bool> inStack(numCourses, false);
        for (int i = 0; i < prerequisites.size(); ++i) {
            if (courses.find(prerequisites[i][1]) == courses.end()) {
                courses[prerequisites[i][1]] = { prerequisites[i][0] };
            }
            else {
                courses[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (isCyclic(i, courses, visited, inStack)) {
                    return false;
                }               
            }
        }
        return true;
    }
};
