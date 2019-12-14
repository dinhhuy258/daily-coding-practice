/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *p = head;
        ListNode *q, *pre, *next;
        ListNode *sortedHead = nullptr;
        while (p != nullptr) {
            next = p->next;
            if (sortedHead == nullptr) {
                sortedHead = p;
                sortedHead->next = nullptr;
            }
            else {
                q = sortedHead;
                pre = nullptr;
                while(q != nullptr && p->val > q->val) {
                    pre = q;
                    q = q->next;
                }
                if (pre == nullptr) {
                    p->next = sortedHead;
                    sortedHead = p;
                }
                else {
                    pre->next = p;
                    p->next = q;
                }
            }
            
            p = next;
        }
        
        return sortedHead;
    }
};
