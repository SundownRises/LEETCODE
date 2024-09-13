class Solution {
public:
int distanceSquared(vector<int>& p1, vector<int>& p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
            vector<int> distances = {
            distanceSquared(p1, p2), distanceSquared(p1, p3), distanceSquared(p1, p4),
            distanceSquared(p2, p3), distanceSquared(p2, p4), distanceSquared(p3, p4)
        };
        
        sort(distances.begin(), distances.end());
        
        return distances[0] > 0 && 
               distances[0] == distances[1] && 
               distances[1] == distances[2] && 
               distances[2] == distances[3] && 
               distances[4] == distances[5];

    }
};