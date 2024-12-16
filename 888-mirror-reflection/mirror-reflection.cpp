class Solution {
public:
    int mirrorReflection(int p, int q) {
                int lcm = (p * q) / gcd(p, q);
        int m = lcm / q; 
        int k = lcm / p;

        if (m % 2 == 0 && k % 2 == 1) return 2;
        if (m % 2 == 1 && k % 2 == 1) return 1;
        return 0;
    }
    
};