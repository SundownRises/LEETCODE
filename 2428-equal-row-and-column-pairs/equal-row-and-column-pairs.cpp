class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
                int n = grid.size();
        unordered_map<string, int> rowMap;
        int count = 0;

        for (int i = 0; i < n; ++i) {
            string rowKey = "";
            for (int j = 0; j < n; ++j) {
                rowKey += to_string(grid[i][j]) + ",";
            }
            rowMap[rowKey]++;
        }

        for (int j = 0; j < n; ++j) {
            string colKey = "";
            for (int i = 0; i < n; ++i) {
                colKey += to_string(grid[i][j]) + ",";
            }
            if (rowMap.find(colKey) != rowMap.end()) {
                count += rowMap[colKey];
            }
        }

        return count;
    }
};