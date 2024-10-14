class Solution {
private:
    vector<int> original;
    vector<int> current;
public:
    Solution(vector<int>& nums) {
        original = nums;
        current = nums;
    }
    
    vector<int> reset() {
        current = original;
        return current;    
    }
    
    vector<int> shuffle() {
        vector<int> shuffled = current;
        for (int i = shuffled.size() - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
    int main() {
    vector<int> nums = {1, 2, 3};
    Solution solution(nums);
    
    vector<int> shuffleResult = solution.shuffle();
    for (int num : shuffleResult) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> resetResult = solution.reset();
    for (int num : resetResult) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> shuffleResult2 = solution.shuffle();
    for (int num : shuffleResult2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */