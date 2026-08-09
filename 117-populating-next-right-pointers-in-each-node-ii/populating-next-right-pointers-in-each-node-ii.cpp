class Solution {
public:
    Node* connect(Node* root) {
        Node* level = root;

        while (level) {
            Node dummy(0);
            Node* tail = &dummy;

            for (Node* curr = level; curr; curr = curr->next) {
                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
            }

            level = dummy.next;
        }

        return root;
    }
};