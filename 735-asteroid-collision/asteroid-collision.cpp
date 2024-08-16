class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for (int asteroid : asteroids) {
            bool exploded = false;

            while (!s.empty() && s.top() > 0 && asteroid < 0) {
                if (abs(asteroid) > s.top()) {
                    s.pop(); 
                } else if (abs(asteroid) == s.top()) {
                    s.pop(); 
                    exploded = true;
                    break;
                } else {
                    exploded = true;
                    break; 
                }
            }

            if (!exploded) {
                s.push(asteroid);
            }
        }

        vector<int> result(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            result[i] = s.top();
            s.pop();
        }

        return result;
    }
};