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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // Split linked list into 2 parts
        // p - first part: [0 -> n / 2 + 1]
        // q - second part (n / 2 + 1, n)
        auto p = head;
        auto q = head;
        ListNode* preQ = nullptr;
        while (p != nullptr) {
            p = p->next;
            preQ = q;
            q = q->next;
            if (p) {
                p = p->next;
            }
        }
        preQ->next = nullptr;
        p = head;

        // Revert the second part
        preQ = nullptr;
        while (q != nullptr) {
            auto nextQ = q->next;
            q->next = preQ;
            preQ = q;
            q = nextQ;
        }
        q = preQ;

        // Merge 2 parts
        while (q != nullptr) {
            auto nextP = p->next;
            auto nextQ = q->next;
            p->next = q;
            q->next = nextP;
            p = nextP;
            q = nextQ;
        }
    }
};

