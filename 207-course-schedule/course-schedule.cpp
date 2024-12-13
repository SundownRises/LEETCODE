class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
                vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for (const auto& pair : prerequisites) {
            adj[pair[1]].push_back(pair[0]);
            inDegree[pair[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            
            for (int neighbor : adj[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return count == numCourses;
    }
};