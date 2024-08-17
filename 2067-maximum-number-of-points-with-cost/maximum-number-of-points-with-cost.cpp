class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
    int m = points.size();
    int n = points[0].size();
    
    vector<long long> prev(n, 0);
    vector<long long> curr(n, 0);

    for (int j = 0; j < n; ++j) {
        prev[j] = points[0][j];
    }

    for (int i = 1; i < m; ++i) {
        vector<long long> leftMax(n, 0);
        leftMax[0] = prev[0];
        for (int j = 1; j < n; ++j) {
            leftMax[j] = max(leftMax[j - 1] - 1, prev[j]);
        }

        vector<long long> rightMax(n, 0);
        rightMax[n - 1] = prev[n - 1];
        for (int j = n - 2; j >= 0; --j) {
            rightMax[j] = max(rightMax[j + 1] - 1, prev[j]);
        }

        for (int j = 0; j < n; ++j) {
            curr[j] = points[i][j] + max(leftMax[j], rightMax[j]);
        }

        swap(prev, curr);
    }

    return *max_element(prev.begin(), prev.end());
}

};