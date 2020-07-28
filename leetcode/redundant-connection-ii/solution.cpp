class Solution {
private:
    class Disjoint {
        private:
            std::vector<int> parents;
            std::vector<int> ranks;
        public:
            Disjoint(int n) {
                parents.resize(n);
                ranks.resize(n);
                std::fill(parents.begin(), parents.end(), -1);
                std::fill(ranks.begin(), ranks.end(), 0);
            }

            int find(int i) {
                if (parents[i] == -1) {
                    return i;
                }

                return find(parents[i]);
            }

            bool unionSet(int a, int b) {
                int parentA = find(a);
                int parentB = find(b);

                if (parentA == parentB) {
                    return false;
                }
                else if (ranks[parentA] < ranks[parentB]) {
                    ranks[parentB] += ranks[parentA];
                    parents[parentA] = parentB;
                }
                else {
                    ranks[parentA] += ranks[parentB];
                    parents[parentB] = parentA;
                }

                return true;
            }
    };

    vector<int> getLoop(vector<vector<int>>& edges, int ignoreEdgeIndex) {
        Disjoint disjoint(edges.size() + 1);
        for (int i = 0; i < edges.size(); ++i) {
            if (i == ignoreEdgeIndex) {
                continue;
            }
            auto edge = edges[i];
            if (!disjoint.unionSet(edge[0], edge[1])) {
                return edge;
            }
        }

        return {};
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        auto n = edges.size();
        std::vector<int> inDegrees(n + 1, 0);
        int numZeroInDegree = n;
        int twoIndegree = -1;

        for (int i = 0; i < n; ++i) {
            auto edge = edges[i];
            ++inDegrees[edge[1]];
            if (inDegrees[edge[1]] == 1) {
                --numZeroInDegree;
            }
            else if (inDegrees[edge[1]] == 2) {
                twoIndegree = edge[1];
                // Circle found
                break;
            }
        }

        if (twoIndegree != -1) {
            bool checkLoop = false;
            for (int i = n - 1; i >= 0; --i) {
                auto edge = edges[i];
                if (twoIndegree == edge[1] && !checkLoop) {
                    if (getLoop(edges, i).empty()) {
                        return edge;
                    }
                    checkLoop = true;
                }
                else if (twoIndegree == edge[1]) {
                    // We have only one loop
                    return edge;
                }
            }
        }

        return getLoop(edges, -1);
    }
};

