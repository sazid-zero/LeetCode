class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;
        ListNode* current = head;

        while (true) {
            ListNode* groupStart = current;
            int count = 0;

            while (current && count < k) {
                current = current->next;
                count++;
            }

            if (count < k) break;
            
            ListNode* prev = current;
            ListNode* node = groupStart;

            for (int i = 0; i < k; ++i) {
                ListNode* next = node->next;
                node->next = prev;
                prev = node;
                node = next;
            }

            // Connect reversed group
            prevGroupEnd->next = prev;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};