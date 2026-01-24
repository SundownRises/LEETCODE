class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<map<string, int>> st;
        st.push({});
        
        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                st.push({});
                i++;
            } 
            else if (formula[i] == ')') {
                i++;
                int mul = 0;
                while (i < n && isdigit(formula[i])) {
                    mul = mul * 10 + (formula[i] - '0');
                    i++;
                }
                if (mul == 0) mul = 1;
                auto top = st.top();
                st.pop();
                for (auto &p : top)
                    st.top()[p.first] += p.second * mul;
            } 
            else {
                string atom;
                atom += formula[i++];
                while (i < n && islower(formula[i]))
                    atom += formula[i++];
                
                int cnt = 0;
                while (i < n && isdigit(formula[i])) {
                    cnt = cnt * 10 + (formula[i] - '0');
                    i++;
                }
                if (cnt == 0) cnt = 1;
                st.top()[atom] += cnt;
            }
        }
        
        string ans;
        for (auto &p : st.top()) {
            ans += p.first;
            if (p.second > 1)
                ans += to_string(p.second);
        }
        return ans;
    }
};

