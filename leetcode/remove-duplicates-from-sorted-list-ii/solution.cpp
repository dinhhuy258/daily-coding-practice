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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* headAns = nullptr;
        ListNode* tailAns = nullptr;
        ListNode* p = head;
        ListNode* q = head->next;
        while (p != nullptr) {
            if (q == nullptr || p->val != q->val) {
                p->next = nullptr;
                if (headAns == nullptr) {
                    headAns = p;
                    tailAns = headAns;
                }
                else {
                    tailAns->next = p;
                    tailAns = p;
                }
                p = q;
                if (p != nullptr) {
                    q = p->next;
                }
            }
            else {
                while (q != nullptr && p->val == q->val) {
                    p = q;
                    q = q->next;
                }
                p = q;
                if (p == nullptr) {
                    break;
                }
                q = p->next;
            }
        }
        return headAns;
    }
};

