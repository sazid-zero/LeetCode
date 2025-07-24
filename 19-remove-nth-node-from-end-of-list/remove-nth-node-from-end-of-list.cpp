/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }

    
            ListNode* newHead = nullptr;
            ListNode* tail = nullptr;
            temp = head;
            int i = 0;
            int ind = size-n;

            while (temp != nullptr) {
                if (i != ind) {
                    ListNode* newNode = new ListNode(temp->val);
                    if (newHead == nullptr) {
                        newHead = newNode;
                        tail = newHead;
                    } else {
                        tail->next = newNode;
                        tail = tail->next;
                    }
                }
                temp = temp->next;
                i++;
            }

            return newHead;
    }
};