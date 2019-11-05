/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int K) {
    ListNode* head = nullptr;
    ListNode* p = A;
    ListNode* preTail = nullptr;
    while(p != nullptr) {
        int count = 1;
        ListNode* tail = p;
        ListNode* q = p;
        while(count <= K) {
            ListNode* nextP = p->next;
            p->next = q;
            q = p;
            p = nextP;
            ++count;
        }
        if (head == nullptr) {
            head = q;
        }
        tail->next = nullptr;
        if (preTail != nullptr) {
            preTail->next = q;
        }
        preTail = tail;
    }
    return head;
}
