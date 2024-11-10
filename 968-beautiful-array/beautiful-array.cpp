class Solution {
public:
    vector<int> construct(int n) {
    if (n == 1) return {1};
    vector<int> result;
    
    vector<int> odd = construct((n + 1) / 2); 
    vector<int> even = construct(n / 2);      
    
    for (int x : odd) result.push_back(2 * x - 1); 
    for (int x : even) result.push_back(2 * x);     
    
    return result;
}

vector<int> beautifulArray(int n) {
    return construct(n);
}
        
    
};