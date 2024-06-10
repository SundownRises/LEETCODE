class Solution {
public:
vector<int> splitVersion(const string& version) {
    vector<int> result;
    stringstream ss(version);
    string segment;
    
    while (getline(ss, segment, '.')) {
        result.push_back(stoi(segment));
    }
    
    return result;
}
int compareVersion(string version1, string version2) {
    vector<int> v1 = splitVersion(version1);
    vector<int> v2 = splitVersion(version2);
    
    int length = max(v1.size(), v2.size());
    
    for (int i = 0; i < length; ++i) {
        int revision1 = i < v1.size() ? v1[i] : 0;
        int revision2 = i < v2.size() ? v2[i] : 0;
        
        if (revision1 < revision2) {
            return -1;
        } else if (revision1 > revision2) {
            return 1;
        }
    }
    
    return 0;
    }
};