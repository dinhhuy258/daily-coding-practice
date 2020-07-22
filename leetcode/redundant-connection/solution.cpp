class Solution {
    class Disjoint {
        private:
            std::vector<int> parents;
        public:
            Disjoint(int n) {
                parents.resize(n);
                std::fill(parents.begin(), parents.end(), -1);
            }

            int find(int i) {
                if (parents[i] == -1) {
                    return i;
                }

                return find(parents[i]);
            }

            void unionSet(int a, int b) {
                int parentA = find(a);
                int parentB = find(b);

                parents[parentB] = parentA;
            }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        auto disjoint = Disjoint(edges.size() + 1);

        for (auto &edge: edges) {
            if (disjoint.find(edge[0]) == disjoint.find(edge[1])) {
                return edge;
            }

            disjoint.unionSet(edge[0], edge[1]);
        }
        return {};
    }
};

