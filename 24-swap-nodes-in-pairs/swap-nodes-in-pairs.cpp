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
    ListNode* swapPairs(ListNode* head) {
        ListNode* list = new ListNode();
        ListNode* temp = list;

        while (head) {
            if (head->next != nullptr) {
                ListNode* second = new ListNode(head->next->val);
                ListNode* first = new ListNode(head->val);
                
                temp->next = second;
                temp = temp->next; 
                temp->next = first; 
                temp = temp->next;         
                head = head->next->next; 
            }
            else {
                temp->next = new ListNode(head->val);
                head = head->next;
            }
        }

        return list->next;
    }
};