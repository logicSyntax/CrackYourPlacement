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
    ListNode* partition(ListNode* head, int x) {
        ListNode* tail1 = new ListNode(-1);
        ListNode* tail2 = new ListNode(-1);
        ListNode* head1 = tail1;
        ListNode* head2 = tail2;

        while(head != NULL) {
            if(head->val < x) {
                tail1->next = head;
                tail1 = tail1->next;
                head = head->next;
                tail1->next = NULL;
            } else {
                tail2->next = head;
                tail2 = tail2->next;
                head = head->next;
                tail2->next = NULL;
            }   
        }

        tail1->next = head2->next;

        return head1->next;
    }
};