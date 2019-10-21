class NumMatrix {
private:
    std::vector<std::vector<int>> nodes;

    void update(int i, int j, int delta) {
        for(; j < nodes[i].size(); j += (j & -j)) {
            nodes[i][j] += delta;
        }
    }

    int query(int i, int j) {
        int sum = 0;
        for (; j > 0; j -= (j & -j)) {
            sum += nodes[i][j];
        }
        return sum;
    }
public:
    NumMatrix(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        nodes.resize(matrix.size());
        std::for_each(nodes.begin(), nodes.end(), std::bind2nd(std::mem_fun_ref(&std::vector<int>::resize), matrix[0].size() + 1));

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                update(i, j + 1, matrix[i][j]);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += query(i, col2 + 1) - query(i, col1);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
