class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::list<std::string> paths;
        char *token = std::strtok(const_cast<char*>(path.c_str()), "/");
        while( token != nullptr ) {
            if (std::string(token) == "..") {
                if (!paths.empty()) {
                    paths.pop_back();
                }
            }
            else if (std::string(token) != ".") {
                paths.push_back(token);
            }
            token = strtok(nullptr, "/");

        }
        std::string canonicalPath = "";
        while(!paths.empty()) {
            canonicalPath = canonicalPath + "/" + paths.front();
            paths.pop_front();
        }
        return canonicalPath == "" ? "/" : canonicalPath;
    }
};