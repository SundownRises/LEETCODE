/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
                unordered_map<int,int> inMap;
        for (int i = 0; i < inorder.size(); ++i) inMap[inorder[i]] = i;
        int postIndex = postorder.size() - 1;
        return build(postorder, inMap, postIndex, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& postorder, unordered_map<int,int>& inMap, int& postIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;
        int val = postorder[postIndex--];
        TreeNode* root = new TreeNode(val);
        int inIndex = inMap[val];
        root->right = build(postorder, inMap, postIndex, inIndex + 1, inEnd);
        root->left = build(postorder, inMap, postIndex, inStart, inIndex - 1);
        return root;
    }
};
