/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* head = A;
    ListNode* p = A;
    while (p != nullptr && p->next != nullptr) {
        if (p->val == p->next->val) {
            // delete node p
            if (p == head) {
                ListNode* deleteNode = p;
                p = p->next;      
                head = p;
                delete deleteNode;
            }
            else {
                ListNode* deleteNode = p->next;
                p->next = p->next->next;
                delete deleteNode;
            }
        }
        else {
            p = p->next;
        }
    }
    return head;
}
