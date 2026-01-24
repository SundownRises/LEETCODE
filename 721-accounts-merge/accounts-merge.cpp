class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int x, int y) {
            parent[find(x)] = find(y);
        };

        unordered_map<string, int> emailToIndex;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (emailToIndex.count(accounts[i][j]))
                    unite(i, emailToIndex[accounts[i][j]]);
                else
                    emailToIndex[accounts[i][j]] = i;
            }
        }

        unordered_map<int, set<string>> groups;
        for (auto& [email, idx] : emailToIndex)
            groups[find(idx)].insert(email);

        vector<vector<string>> result;
        for (auto& [idx, emails] : groups) {
            vector<string> acc;
            acc.push_back(accounts[idx][0]);
            acc.insert(acc.end(), emails.begin(), emails.end());
            result.push_back(acc);
        }

        return result;
    }
};
