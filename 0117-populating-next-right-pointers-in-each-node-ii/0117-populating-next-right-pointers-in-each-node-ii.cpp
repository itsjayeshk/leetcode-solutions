class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            Node* prev = nullptr;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if (prev != nullptr) {
                    prev->next = curr;
                }

                prev = curr;

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }

                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }

            prev->next = nullptr;
        }

        return root;
    }
};

