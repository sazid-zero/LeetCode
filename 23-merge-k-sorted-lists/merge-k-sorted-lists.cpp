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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* list = new ListNode();
        ListNode* temp = list;
        vector<int>v;
        for(int i = 0; i<lists.size(); i++){
            while(lists[i]!=nullptr){
                v.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        sort(v.begin(), v.end());

        for(int i = 0; i<v.size(); i++){
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }

        return list->next;
    }
};