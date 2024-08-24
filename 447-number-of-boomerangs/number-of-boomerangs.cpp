class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
               int boomerangs = 0;
        
        for (const auto& p1 : points) {
            unordered_map<int, int> distanceMap;
            
            for (const auto& p2 : points) {
                int dx = p1[0] - p2[0];
                int dy = p1[1] - p2[1];
                int dist = dx * dx + dy * dy;
                
                distanceMap[dist]++;
            }
            
            for (const auto& pair : distanceMap) {
                int count = pair.second;
                boomerangs += count * (count - 1);
            }
        }
        
        return boomerangs;
    }
};