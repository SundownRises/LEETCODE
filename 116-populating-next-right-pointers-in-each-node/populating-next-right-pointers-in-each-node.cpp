class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* level_start = root;

        while (level_start->left) {
            Node* current = level_start;

            while (current) {
                current->left->next = current->right;
                if (current->next)
                    current->right->next = current->next->left;

                current = current->next;
            }

            level_start = level_start->left;
        }

        return root;
    }
};
