class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
            vector<int> answer;
    vector<int> indices;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == x) {
            indices.push_back(i);
        }
    }

    for (int q : queries) {
        if (q > indices.size()) {
            answer.push_back(-1);
        } else {
            answer.push_back(indices[q - 1]); 
        }
    }

    return answer;
    }
};