class Solution {
private:
    /**
     * @param: a string 
     * @return a reverse string
     */
    std::string reverse(std::string input) {
        std::string output = std::move(input);
        int i = 0;
        int j = output.size() - 1;
        while(i < j) {
            std::swap(output[i], output[j]);
            ++i;
            --j;
        }
        return output;
    }
    
    /**
     * @param node: a current processing node
     * @param adjacencyLists: an adjacency lists
     * @param visited: a vector which tell whether a node is visited or not
     * @param inStack: a vector which tell whether node is in current processing 
     * @param order: the result
     * @return: true if order is valid, otherwise false
     */
    bool topologicalSort(char node,
                         std::unordered_map<char, std::string>& adjacencyLists, 
                         std::vector<bool>& visited, 
                         std::vector<bool>& inStack,
                         std::string& order) {
        visited[node - 'a'] = true;
        inStack[node - 'a'] = true;
        std::string& neighbors =  adjacencyLists[node];
        for (char neighbor: neighbors) {
            if (inStack[neighbor - 'a']) {
                // Invalid order
                order = "";
                return false;
            }
            if (visited[neighbor - 'a']) {
                continue;
            }
            if (!topologicalSort(neighbor, adjacencyLists, visited, inStack, order)) {
                // Invalid order
                return false;
            }
        }
        order += node;
        inStack[node - 'a'] = false;
        return true;
    }
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    std::string alienOrder(std::vector<std::string> &words) {
        std::unordered_map<char, std::string> adjacencyLists;
        std::vector<bool> inAlphabet(26, false);
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = 0; j < std::min(words[i].size(), words[i + 1].size()); ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    if (adjacencyLists.find(words[i][j]) == adjacencyLists.end()) {
                        adjacencyLists[words[i][j]] = words[i + 1][j];
                    }
                    else {
                        adjacencyLists[words[i][j]] += words[i + 1][j];
                    }
                    break;
                }
            }
            if (i == 0) {
                for (int j = 0; j < words[i].size(); ++j) {
                    inAlphabet[words[i][j] - 'a'] = true;
                }
            }
            for (int j = 0; j < words[i + 1].size(); ++j) {
                inAlphabet[words[i + 1][j] - 'a'] = true;
            }
        }
        std::string order = "";
        std::vector<bool> visited(26, false); 
        std::vector<bool> inStack(26, false);
        for (int i = 'a'; i <= 'z'; ++i) {
            if (adjacencyLists.find(i) != adjacencyLists.end() && !visited[i - 'a']) {
                if (!topologicalSort(i, adjacencyLists, visited, inStack, order)) {
                    // Invalid order
                    return order;
                }
            }
        }
        // Reverse order
        order = reverse(order);
        std::string result = "";
        int i = 0;
        int j = 0;
        while(i < order.size() && j < inAlphabet.size()) {
            if (inAlphabet[j]) {
                if (visited[j]) {
                    ++j;
                }
                else {
                    if (j < (order[i] - 'a')) {
                        result += (j++ + 'a');
                    }
                    else {
                        result += order[i++];
                    }
                }
            }
            else {
                ++j;
            }
        }
        while(i < order.size()) {
            result += order[i++];
        }
        while(j < inAlphabet.size()) {
            if (inAlphabet[j]) {
                result += (j + 'a');
            }
            ++j;
        }
        return result;
    }
};
