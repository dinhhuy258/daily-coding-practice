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
    ListNode* middleNode(ListNode* head) {
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast != nullptr) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        
        return slow;
    }
};
