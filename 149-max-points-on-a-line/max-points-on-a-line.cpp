class Solution {
public:
int computeGCD(int a, int b) {
    if (b == 0)
        return a;
    return computeGCD(b, a % b);
}

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) * 100000 + hash<int>()(p.second);
    }
};
    int maxPoints(vector<vector<int>>& points) {
                if (points.empty()) return 0;
        if (points.size() == 1) return 1;
        
        int maxPointsOnLine = 0;
        int n = points.size();
        
        for(int i = 0; i < n; ++i){
            unordered_map<pair<int, int>, int, pair_hash> slopeCount;
            int samePoint = 0; 
            int currentMax = 0;
            
            for(int j = 0; j < n; ++j){
                if(i == j){
                    continue;
                }
                
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                if(dx == 0 && dy == 0){
                    samePoint++;
                    continue;
                }
                
                if(dx == 0){
                    dy = 1;
                }
                else if(dy == 0){
                    dx = 1;
                }
                else{
                    int gcd = computeGCD(abs(dx), abs(dy));
                    dx /= gcd;
                    dy /= gcd;
                    
                    if(dx < 0){
                        dx = -dx;
                        dy = -dy;
                    }
                }
                
                pair<int, int> slope = {dy, dx};
                slopeCount[slope]++;
                currentMax = max(currentMax, slopeCount[slope]);
            }
            
            maxPointsOnLine = max(maxPointsOnLine, currentMax + 1); 
        }
        
        return maxPointsOnLine;
    }
};