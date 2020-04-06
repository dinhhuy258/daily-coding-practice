class Solution {
public:
    std::vector<std::vector<string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (auto& str: strs) {
            auto sortedWord = str;
            std::sort(sortedWord.begin(), sortedWord.end());
            if (groups.find(sortedWord) == groups.end()) {
                groups[sortedWord] = { str };
            }
            else {
                groups[sortedWord].push_back(str);
            }
        }
        
        std::vector<std::vector<string>> result;
        for (auto& group: groups) {
            result.push_back(group.second);
        }
        return result;
    }
};
