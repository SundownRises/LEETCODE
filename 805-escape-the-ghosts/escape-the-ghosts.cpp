class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
                int playerDistance = manhattanDistance(0, 0, target[0], target[1]);

        for (const auto& ghost : ghosts) {
            int ghostDistance = manhattanDistance(ghost[0], ghost[1], target[0], target[1]);
            if (ghostDistance <= playerDistance) {
                return false; 
            }
        }

        return true;
    }

private:
    int manhattanDistance(int x1, int y1, int x2, int y2) {
        return abs(x2 - x1) + abs(y2 - y1);
    
    }
};