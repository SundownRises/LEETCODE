class Solution {
public:
    string solveEquation(string equation) {
        int lhs_x = 0, lhs_const = 0, rhs_x = 0, rhs_const = 0;
        
        size_t equal_sign = equation.find('=');
        string lhs = equation.substr(0, equal_sign);
        string rhs = equation.substr(equal_sign + 1);
        
        auto process_side = [](const string& s, int& x_coeff, int& constant) {
            istringstream ss(s);
            int sign = 1, num = 0;
            bool has_num = false;
            char prev = '+';
            
            for (int i = 0; i <= s.size(); ++i) {
                char c = (i < s.size() ? s[i] : '+');
                
                if (isdigit(c)) {
                    num = num * 10 + (c - '0');
                    has_num = true;
                } else if (c == 'x') {
                    if (has_num) {
                        x_coeff += sign * num;
                    } else {
                        x_coeff += sign;
                    }
                    num = 0;
                    has_num = false;
                } else if (c == '+' || c == '-') {
                    if (prev != 'x') {
                        constant += sign * num;
                    }
                    sign = (c == '+') ? 1 : -1;
                    num = 0;
                    has_num = false;
                }
                prev = c;
    }
};
        process_side(lhs, lhs_x, lhs_const);
        process_side(rhs, rhs_x, rhs_const);
        
        int x_total = lhs_x - rhs_x;
        int const_total = rhs_const - lhs_const;
        
        if (x_total == 0) {
            if (const_total == 0) {
                return "Infinite solutions";
            } else {
                return "No solution";
            }
        }
        
        return "x=" + to_string(const_total / x_total);
    }
};