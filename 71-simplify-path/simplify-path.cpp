class Solution {
public:
    string simplifyPath(string path) {
    vector<string> components;
    stringstream ss(path);
    string temp;
    
    while (getline(ss, temp, '/')) {
        if (temp == "" || temp == ".") {
            continue;
        }
        if (temp == "..") {
            if (!components.empty()) {
                components.pop_back();
            }
        } else {
            components.push_back(temp);
        }
    }
    
    string simplifiedPath = "/";
    for (size_t i = 0; i < components.size(); ++i) {
        simplifiedPath += components[i];
        if (i != components.size() - 1) {
            simplifiedPath += "/";
        }
    }
    
    return simplifiedPath;


    }
};