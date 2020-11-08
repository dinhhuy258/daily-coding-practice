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
private:
    ListNode* reverse(ListNode* p) {
        ListNode *current, *next, *previous;
        current = p;
        previous = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        return previous;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        int remaining = 0;
        ListNode *previous = nullptr;
        while(l1 != nullptr || l2 != nullptr) {
            int value = (l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0) + remaining;
            remaining = value / 10;
            value = value % 10;
            ListNode *node = new ListNode(value);
            node->next = previous;
            previous = node;
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
        }
        if (remaining != 0) {
            ListNode *node = new ListNode(remaining);
            node->next = previous;
            previous = node;
        }

        return previous;
    }
};

