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
    std::pair<ListNode*, ListNode*> splitList(ListNode* root) {
        ListNode *p = root;
        ListNode *q = root;
        while (p && p->next) {
            p = p->next;
            if (p && p->next) {
                q = q->next;
                p = p->next;
            }
        }
        p = q->next;
        q->next = nullptr;

        return std::make_pair(root, p);
    }

    ListNode* merge(ListNode* firstHalf, ListNode* secondHalf) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while (firstHalf != nullptr && secondHalf != nullptr) {
            ListNode *temp;
            if (firstHalf->val < secondHalf->val) {
                temp = firstHalf;
                firstHalf = firstHalf->next;
            }
            else {
                temp = secondHalf;
                secondHalf = secondHalf->next;
            }
            if (head == nullptr) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
                tail->next = nullptr;
            }
        }
        if (firstHalf != nullptr) {
            tail->next = firstHalf;
        }
        if (secondHalf != nullptr) {
            tail->next = secondHalf;
        }

        return head;
    }

    ListNode* mergeSort(ListNode* root) {
        if (root == nullptr || root->next == nullptr) {
            return root;
        }
        auto heads = splitList(root);
        auto firstHalf = mergeSort(heads.first);
        auto secondHalf = mergeSort(heads.second);

        return merge(firstHalf, secondHalf);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};

