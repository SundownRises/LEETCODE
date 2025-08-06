class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        backtrack(s, 0, {}, result);
        return result;
    }
private:
    void backtrack(string &s, int start, vector<string> path, vector<string> &result) {
        if (path.size() == 4) {
            if (start == s.size()) result.push_back(join(path));
            return;
        }
        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.size()) break;
            string segment = s.substr(start, len);
            if ((segment.size() > 1 && segment[0] == '0') || stoi(segment) > 255) continue;
            path.push_back(segment);
            backtrack(s, start + len, path, result);
            path.pop_back();
        }
    }
    string join(vector<string> &path) {
        string ip;
        for (int i = 0; i < path.size(); ++i) {
            if (i) ip += ".";
            ip += path[i];
        }
        return ip;
    }
};

