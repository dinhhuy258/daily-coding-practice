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
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *p = head->next;
        ListNode *q = head;
        head = p;
        ListNode *preQ = nullptr;
        while (p != nullptr) {
            ListNode* nextP = p->next;
            p->next = q;
            q->next = nextP;
            if (preQ != nullptr) {
                preQ->next = p;
            }
            preQ = q;
            p = nextP;
            q = nextP;
            if (nextP != nullptr) {
                p = nextP->next;
            }
        }

        return head;
    }
};

